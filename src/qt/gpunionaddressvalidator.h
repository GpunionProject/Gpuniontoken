// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017 The Gpunion Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GPUNION_QT_GPUNIONADDRESSVALIDATOR_H
#define GPUNION_QT_GPUNIONADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class GpunionAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit GpunionAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Gpunion address widget validator, checks for a valid gpunion address.
 */
class GpunionAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit GpunionAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // GPUNION_QT_GPUNIONADDRESSVALIDATOR_H
