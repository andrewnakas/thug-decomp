#ifndef GAME_IDSTRING_H
#define GAME_IDSTRING_H
#ifndef M2CTX /* C++ only; m2c parses these headers as C */

/* Object at 0x00104008..: a serial id (from a global counter) and a char buffer. */
struct IdString {
    int m0;
    int m_id;
    char* m_str;

    IdString();
    IdString(const char* s);
    IdString(const IdString& o);
    IdString& operator=(const IdString& o);
};

#endif /* M2CTX */
#endif
