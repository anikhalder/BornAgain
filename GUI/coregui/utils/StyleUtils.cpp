//* ************************************************************************* //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/utils/StyleUtils.h
//! @brief     DefinesStyleUtils namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
//* ************************************************************************* //

#include "StyleUtils.h"

QString StyleUtils::propertyTreeStyle()
{
    QString result;

    // lines arount cell content
    result += "QTreeView::item {"
              "    border-bottom: 1px solid #c7c8c9; "
              "    border-right: 1px solid #c7c8c9;}"
              "QTreeView::branch {border-bottom: 1px solid #c7c8c9;}";

    // styling of branch to restore open/closed signs eliminated by previous styling
    result += "QTreeView::branch:has-children:!has-siblings:closed,"
              "QTreeView::branch:closed:has-children:has-siblings {"
              "padding:2px 2px 2px 2px;border-image: none;"
              "image: url(:/images/caret-right.svg);}"
              "QTreeView::branch:open:has-children:!has-siblings,"
              "QTreeView::branch:open:has-children:has-siblings  {"
              "padding:2px 2px 2px 2px;border-image: none; image: url(:/images/caret-down.svg);"
            "}";

    // background of selected rows restored
    result += "QTreeView::item:selected{background:#3daee9;}";

    return result;
}

QString StyleUtils::realtimeTreeStyle()
{
    QString result =
    "QTreeView::branch {background: "
    "palette(base);}QTreeView::branch:has-siblings:!adjoins-item "
    "{border-image: url(:/images/treeview-vline.png) 0;}QTreeView::branch:has-siblings:"
    "adjoins-item {border-image: url(:/images/treeview-branch-more.png) 0;}QTreeView::branch:"
    "!has-children:!has-siblings:adjoins-item {border-image: "
    "url(:/images/treeview-branch-end.png) "
    "0;}QTreeView::branch:has-children:!has-siblings:closed"
    ",QTreeView::branch:closed:has-children:has-siblings {border-image: none;image: "
    "url(:/images/"
    "treeview-branch-closed.png);}QTreeView::branch:open:has-children:!has-siblings,"
    "QTreeView::branch:open:has-children:has-siblings  {border-image: none;image: "
    "url(:/images/treeview-branch-open.png);}";

    return result;
}