// Copyright (c) 2016 The Bitcoin Core developers
// Copyright (c) 2017 The Gpunion Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GPUNION_QT_TEST_RPC_NESTED_TESTS_H
#define GPUNION_QT_TEST_RPC_NESTED_TESTS_H

#include <QObject>
#include <QTest>

#include "txdb.h"
#include "txmempool.h"

class RPCNestedTests : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
    void rpcNestedTests();

private:
    CCoinsViewDB *pcoinsdbview;
};

#endif // GPUNION_QT_TEST_RPC_NESTED_TESTS_H
