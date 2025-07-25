/*

    This file is part of the KDE project, module kfile.
    SPDX-FileCopyrightText: 2000 Geert Jansen <jansen@kde.org>
    SPDX-FileCopyrightText: 2000 Kurt Granroth <granroth@kde.org>
    SPDX-FileCopyrightText: 1997 Christoph Neerfeld <chris@kde.org>
    SPDX-FileCopyrightText: 2002 Carsten Pfeiffer <pfeiffer@kde.org>

    SPDX-License-Identifier: LGPL-2.0-only
*/

#ifndef KICONBUTTON_H
#define KICONBUTTON_H

#include "kiconwidgets_export.h"

#include <QPushButton>
#include <memory>

#include <kiconloader.h>

/*!
 * \class KIconButton
 * \inmodule KIconWidgets
 *
 * \brief A pushbutton for choosing an icon.
 *
 * Pressing on the button will open a
 * KIconDialog for the user to select an icon. The current icon will be
 * displayed on the button.
 *
 * \sa KIconDialog
 */
class KICONWIDGETS_EXPORT KIconButton : public QPushButton
{
    Q_OBJECT

    /*!
     * \property KIconButton::icon
     */
    Q_PROPERTY(QString icon READ icon WRITE setIcon RESET resetIcon NOTIFY iconChanged USER true)

    /*!
     * \property KIconButton::iconSize
     */
    Q_PROPERTY(int iconSize READ iconSize WRITE setIconSize)

    /*!
     * \property KIconButton::strictIconSize
     */
    Q_PROPERTY(bool strictIconSize READ strictIconSize WRITE setStrictIconSize)

public:
    /*!
     * Constructs a KIconButton using the global icon loader.
     *
     * \a parent The parent widget.
     */
    explicit KIconButton(QWidget *parent = nullptr);

    ~KIconButton() override;

    /*!
     * Sets a strict icon size policy for allowed icons. When true,
     * only icons of the specified group's size in setIconType() are allowed,
     * and only icons of that size will be shown in the icon dialog.
     */
    void setStrictIconSize(bool b);

    /*!
     * Returns true if a strict icon size policy is set.
     */
    bool strictIconSize() const;

    /*!
     * Sets the icon group and context. Use KIconLoader::NoGroup if you want to
     * allow icons for any group in the given context.
     */
    void setIconType(KIconLoader::Group group, KIconLoader::Context context, bool user = false);

    /*!
     * Sets the button's initial icon.
     */
    void setIcon(const QString &icon);

    /*!
     * Sets the button's initial icon.
     */
    void setIcon(const QIcon &icon);

    /*!
     * Resets the icon (reverts to an empty button).
     */
    void resetIcon();

    /*!
     * Returns the name of the selected icon.
     */
    const QString &icon() const;

    /*!
     * Sets the size of the icon to be shown / selected.
     * \sa KIconLoader::StdSizes
     * \sa iconSize
     */
    void setIconSize(int size);
    /*!
     * Returns the icon size set via setIconSize() or 0, if the default
     * icon size will be used.
     */
    int iconSize() const;

    /*!
     * Sets the size of the icon to be shown on the button.
     * \sa KIconLoader::StdSizes
     * \sa buttonIconSize
     * \since 4.1
     */
    void setButtonIconSize(int size);
    /*!
     * Returns the button's icon size.
     * \since 4.1
     */
    int buttonIconSize() const;

    void paintEvent(QPaintEvent *event) override;

    void changeEvent(QEvent *event) override;

Q_SIGNALS:
    /*!
     * Emitted when the icon has changed.
     */
    void iconChanged(const QString &icon);

private:
    std::unique_ptr<class KIconButtonPrivate> const d;

    Q_DISABLE_COPY(KIconButton)
};

#endif // KICONBUTTON_H
