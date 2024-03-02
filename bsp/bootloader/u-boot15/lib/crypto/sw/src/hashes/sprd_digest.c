#include <sprdsha.h>

int sprd_digest_init(hash_state *md, sprd_crypto_algo_t hash_type)
{
    int ret = -1;
    if (hash_type == SPRD_CRYPTO_HASH_SHA1) {
        ret = sha1_init(md);
        return ret;
    }
    if (hash_type == SPRD_CRYPTO_HASH_SHA256) {
        ret = sha256_init(md);
        return ret;
    }

    return ret;
}

int sprd_digest_process(hash_state *md, const unsigned char *in, uint64_t inlen, sprd_crypto_algo_t hash_type)
{
    int ret = -1;
    if (hash_type == SPRD_CRYPTO_HASH_SHA1) {
        ret = sha1_process(md, in, inlen);
        return ret;
    }
    if (hash_type == SPRD_CRYPTO_HASH_SHA256) {
        ret = sha256_process(md, in, inlen);
        return ret;
    }

    return ret;
}

int sprd_digest_done(hash_state *md, unsigned char *out, sprd_crypto_algo_t hash_type)
{
    int ret = -1;
    if (hash_type == SPRD_CRYPTO_HASH_SHA1) {
        ret = sha1_done(md, out);
        return ret;
    }
    if (hash_type == SPRD_CRYPTO_HASH_SHA256) {
        ret = sha256_done(md, out);
        return ret;
    }

    return ret;
}

void sprd_digest_sw(const unsigned char *input, unsigned int ilen, unsigned char *output, sprd_crypto_algo_t hash_type)
{
    if (hash_type == SPRD_CRYPTO_HASH_SHA1) {
        sha1_csum_wd_sw(input, ilen, output);
    }
    if (hash_type == SPRD_CRYPTO_HASH_SHA256) {
        sha256_csum_wd_sw(input, ilen, output);
    }
}
