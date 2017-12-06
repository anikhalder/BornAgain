// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/GroupItem.cpp
//! @brief     Implements class GroupItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "GroupItem.h"
#include "GUIHelpers.h"
#include "GroupItemController.h"
#include "ComboProperty.h"
#include <QDebug>
#include "GUIHelpers.h"

namespace {
QVariant createCombo(const GroupItemController& groupProperty)
{
    ComboProperty result;
    result.setValues(groupProperty.itemLabels());
    result.setCurrentIndex(groupProperty.currentIndex());
    return result.variant();
}

}

const QString GroupItem::T_ITEMS = "Item tag";

GroupItem::GroupItem() : SessionItem(Constants::GroupItemType)
{
    registerTag(T_ITEMS);
    setDefaultTag(T_ITEMS);

    mapper()->setOnValueChange([this]() { onValueChange(); });
}

GroupItem::~GroupItem(){}

void GroupItem::setGroupInfo(const GroupInfo& groupInfo)
{
    if (m_controller)
        throw GUIHelpers::Error("GroupItem::setGroup() -> Error. Attempt to set group twice.");

    m_controller.reset(new GroupItemController);
    m_controller->setGroupInfo(groupInfo);
    m_controller->setGroupItem(this);

    updateComboValue();
}

SessionItem* GroupItem::currentItem() const
{
    return m_controller ? m_controller->currentItem() : nullptr;
}

QString GroupItem::currentType() const
{
    return m_controller->currentType();
}

SessionItem* GroupItem::setCurrentType(const QString& modelType)
{
    m_controller->setCurrentType(modelType);
    updateComboValue();
    return currentItem();
}

QStringList GroupItem::translateList(const QStringList& list) const
{
    // we do not add here the name of itself
    return list;
}

SessionItem* GroupItem::getItemOfType(const QString& type)
{
    return m_controller->getItemOfType(type);
}

void GroupItem::onValueChange()
{
    if (!value().canConvert<ComboProperty>())
        throw GUIHelpers::Error("GroupItem::onValueChange() -> Error. Wrong property type");

    qDebug() << "GroupItem::onValueChange()";

    ComboProperty property = value().value<ComboProperty>();
    if (property.currentIndex() != m_controller->currentIndex()) {
        qDebug() << "GroupItem::onValueChange() -> setting index" << property.currentIndex();
        m_controller->setCurrentIndex(property.currentIndex());
        // because of the delay between ComboProperty change and the change in GroupItem here,
        // we have to emit signals once again to inform other views (i.e. views other than the view
        // were property was changed)
        emitDataChanged(Qt::DisplayRole | Qt::EditRole);
    }
}

void GroupItem::updateComboValue()
{
    setValue(createCombo(*m_controller.get()));
}

