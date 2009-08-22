#include <sys/types.h>
#include "bitwise_string_ops.h"

void string_bitwise_or(const char *left, size_t llen,
                       const char *right, size_t rlen,
                       char *dest)
{
    const char *s = llen < rlen ? left : right;   /* smaller */
    const char *b = llen < rlen ? right : left;   /* bigger  */
    size_t len = MIN(llen,rlen);
    size_t ext = MAX(llen,rlen) - len;
    while (len--)
        *(dest++) = *(s++) | *(b++);
    while (ext--)
        *(dest++) = *(b++);
}

void string_bitwise_xor(const char *left, size_t llen,
                        const char *right, size_t rlen,
                        char *dest)
{
    const char *s = llen < rlen ? left : right;   /* smaller */
    const char *b = llen < rlen ? right : left;   /* bigger  */
    size_t len = MIN(llen,rlen);
    size_t ext = MAX(llen,rlen) - len;
    while (len--)
        *(dest++) = *(s++) ^ *(b++);
    while (ext--)
        *(dest++) = *(b++);
}

void string_bitwise_and(const char *l, size_t llen,
                        const char *r, size_t rlen,
                        char *dest)
{
    size_t len = MIN(llen,rlen);
    while (len--)
        *(dest++) = *(l++) & *(r++);
}

void string_bitwise_not(const char *s, size_t slen,
                        char *dest)
{
    while (slen--)
        *(dest++) = ~(*s++);
}
