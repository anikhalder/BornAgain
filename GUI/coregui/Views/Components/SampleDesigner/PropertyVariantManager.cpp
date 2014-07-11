#include "PropertyVariantManager.h"
#include "DesignerHelper.h"
#include "ParameterizedItem.h"


PropertyVariantManager::PropertyVariantManager(QObject *parent)
    : QtVariantPropertyManager(parent)
{

}


int PropertyVariantManager::materialTypeId()
{
    int result = qMetaTypeId<MaterialProperty>();
    return result;
}

int PropertyVariantManager::groupTypeId()
{
    int result = qMetaTypeId<GroupProperty>();
    return result;
}

int PropertyVariantManager::colorPropertyTypeId()
{
    int result = qMetaTypeId<ColorProperty>();
    return result;
}

bool PropertyVariantManager::isPropertyTypeSupported(int propertyType) const
{
    if (propertyType == materialTypeId())
        return true;
    if (propertyType == groupTypeId())
        return true;
    if (propertyType == colorPropertyTypeId())
        return true;
    return QtVariantPropertyManager::isPropertyTypeSupported(propertyType);
}


int PropertyVariantManager::valueType(int propertyType) const
{
    if (propertyType == materialTypeId())
        return materialTypeId();
    if (propertyType == groupTypeId())
        return groupTypeId();
    if (propertyType == colorPropertyTypeId())
        return colorPropertyTypeId();
    return QtVariantPropertyManager::valueType(propertyType);
}


QVariant PropertyVariantManager::value(const QtProperty *property) const
{
    if (theMaterialValues.contains(property)) {
        QVariant v;
        v.setValue(theMaterialValues[property]);
        return v;
    }
    if (theGroupValues.contains(property)) {
        QVariant v;
        v.setValue(theGroupValues[property]);
        return v;
    }
    if(m_ColorValues.contains(property)) {
        QVariant v;
        v.setValue(m_ColorValues[property]);
        return v;
    }
    return QtVariantPropertyManager::value(property);
}


QString PropertyVariantManager::valueText(const QtProperty *property) const
{
    if (theMaterialValues.contains(property)) {
        return theMaterialValues[property].getName();
    }
    if (theGroupValues.contains(property)) {
        return theGroupValues[property].getValue();
    }
    if (m_ColorValues.contains(property)) {
        return m_ColorValues[property].getText();
    }
    return QtVariantPropertyManager::valueText(property);
}


QIcon PropertyVariantManager::valueIcon(const QtProperty *property) const
{
    if (theMaterialValues.contains(property)) {
        return QIcon(theMaterialValues[property].getPixmap());
    }
    if (m_ColorValues.contains(property)) {
        return QIcon(m_ColorValues[property].getPixmap());
    }
    return QtVariantPropertyManager::valueIcon(property);
}


void PropertyVariantManager::setValue(QtProperty *property, const QVariant &val)
{
    if (theMaterialValues.contains(property)) {
        if( val.userType() != materialTypeId() ) return;
        MaterialProperty mat = val.value<MaterialProperty>();
        theMaterialValues[property] = mat;
        QVariant v2;
        v2.setValue(mat);
        emit propertyChanged(property);
        emit valueChanged(property, v2);
        return;
    }
    if (theGroupValues.contains(property)) {
        if( val.userType() != groupTypeId() ) return;
        GroupProperty group_prop = val.value<GroupProperty>();
        theGroupValues[property] = group_prop;
        QVariant v2;
        v2.setValue(group_prop);
        emit propertyChanged(property);
        emit valueChanged(property, v2);
        return;
    }
    if (m_ColorValues.contains(property)) {
        if( val.userType() != colorPropertyTypeId() ) return;
        ColorProperty mat = val.value<ColorProperty>();
        m_ColorValues[property] = mat;
        QVariant v2;
        v2.setValue(mat);
        emit propertyChanged(property);
        emit valueChanged(property, v2);
        return;
    }
    QtVariantPropertyManager::setValue(property, val);
}


void PropertyVariantManager::initializeProperty(QtProperty *property)
{
    if (propertyType(property) == materialTypeId()) {
        MaterialProperty m;
        theMaterialValues[property] = m;
    }
    if (propertyType(property) == groupTypeId()) {
        GroupProperty m;
        theGroupValues[property] = m;
    }
    if (propertyType(property) == colorPropertyTypeId()) {
        ColorProperty m;
        m_ColorValues[property] = m;
    }

    QtVariantPropertyManager::initializeProperty(property);
}


void PropertyVariantManager::uninitializeProperty(QtProperty *property)
{
    theMaterialValues.remove(property);
    theGroupValues.remove(property);
    m_ColorValues.remove(property);
    QtVariantPropertyManager::uninitializeProperty(property);
}

