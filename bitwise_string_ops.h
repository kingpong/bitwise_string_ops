
#ifndef BITWISE_STRING_OPS_H
#define BITWISE_STRING_OPS_H

#include <sys/types.h>

#ifndef MAX
# define MAX(i,j) (i > j ? i : j)
#endif
#ifndef MIN
# define MIN(i,j) (i < j ? i : j)
#endif

#define string_bitwise_or_result_len(i,j)  (MAX(i,j))
#define string_bitwise_xor_result_len(i,j) (MAX(i,j))
#define string_bitwise_and_result_len(i,j) (MIN(i,j))
#define string_bitwise_not_result_len(i)   (i)

void string_bitwise_or(const char *l, size_t llen, const char *r, size_t rlen, char *dest);
void string_bitwise_xor(const char *l, size_t llen, const char *r, size_t rlen, char *dest);
void string_bitwise_and(const char *l, size_t llen, const char *r, size_t rlen, char *dest);
void string_bitwise_not(const char *s, size_t slen, char *dest);

#endif /* BITWISE_STRING_OPS_H */

