// Copyright (c) 2009-2019 The Bitcoin Core developers 
// Copyright (c) 2019-2021 The Cerebral Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CEREBRALCOIN_CRYPTO_HMAC_SHA512_H
#define CEREBRALCOIN_CRYPTO_HMAC_SHA512_H

#include <crypto/sha512.h>

#include <stdint.h>
#include <stdlib.h>

/** A hasher class for HMAC-SHA-512. */
class CHMAC_SHA512
{
private:
    CSHA512 outer;
    CSHA512 inner;

public:
    static const size_t OUTPUT_SIZE = 64;

    CHMAC_SHA512(const unsigned char* key, size_t keylen);
    CHMAC_SHA512& Write(const unsigned char* data, size_t len)
    {
        inner.Write(data, len);
        return *this;
    }
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
};

#endif // CEREBRALCOIN_CRYPTO_HMAC_SHA512_H
