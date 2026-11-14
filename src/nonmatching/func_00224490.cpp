/* fuzzy: 87.4 */
/* blocked: the game zeroes `set` at the switch join and keeps the digit branch's `set = 0`; declaring `int set =
   0;` before the switch gives the right size (33 words, same fuzzy) but the zero lands in the switch's delay slot in
   $a1; after the switch cse drops the branch store; directed search: no match. */
struct Glyph_00224490 {
    unsigned short code;
    unsigned short pad;
};

struct Range_00224490 {
    unsigned short base;
    unsigned short first;
};

extern int D_0038882C;
extern char D_00371CB0[];
extern Glyph_00224490 D_00354D28[];
extern Range_00224490 D_00354DB0[];
extern "C" void func_00103F28(char* fmt, ...);

unsigned short Glyph_00224490(unsigned char c)
{
    if (!D_0038882C && c == 0x5F) {
        c = 0x2D;
    }
    switch ((char)c) {
    case (char)0xDF:
        c = 0x42;
        break;
    case (char)0xC4:
        c = 0x41;
        break;
    case (char)0xDC:
        c = 0x55;
        break;
    case (char)0xD6:
        c = 0x4F;
        break;
    case (char)0xE0:
    case (char)0xE2:
    case (char)0xE4:
        c = 0x61;
        break;
    case (char)0xE8:
    case (char)0xE9:
    case (char)0xEA:
    case (char)0xEB:
        c = 0x65;
        break;
    case (char)0xEC:
    case (char)0xEE:
    case (char)0xEF:
        c = 0x69;
        break;
    case (char)0xF9:
    case (char)0xFB:
    case (char)0xFC:
        c = 0x75;
        break;
    case (char)0xE7:
        c = 0x63;
        break;
    case (char)0x9C:
    case (char)0xF2:
    case (char)0xF4:
    case (char)0xF6:
        c = 0x6F;
        break;
    }
    int set;
    int start = 0;
    if (c >= 0x20 && c <= 0x2F) {
        start = 1;
    } else if (c >= 0x30 && c <= 0x39) {
        set = 0;
    } else if (c >= 0x3A && c <= 0x40) {
        start = 0xB;
    } else if (c >= 0x41 && c <= 0x5A) {
        set = 1;
    } else if (c >= 0x5B && c <= 0x60) {
        start = 0x25;
    } else if (c >= 0x61 && c <= 0x7A) {
        set = 2;
    } else if (c >= 0x7B && c <= 0x7E) {
        start = 0x3F;
    } else {
        func_00103F28(D_00371CB0, c);
        return 0;
    }
    unsigned short r;
    if (start) {
        r = D_00354D28[c - 0x20 - (start - 1)].code;
    } else {
        r = D_00354DB0[set].base + c - D_00354DB0[set].first;
    }
    return r;

}
