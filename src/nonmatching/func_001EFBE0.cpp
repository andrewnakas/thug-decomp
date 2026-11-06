/* fuzzy: 80.4 */
extern "C" unsigned char* func_001EB070(unsigned char* p);
extern "C" void func_001E6B30(void* p);
extern "C" unsigned char* func_001ED6B8(void* p, unsigned char* q, int a);

struct Entry_001EFBE0 {
    char m[0x14];
};

struct Parser_001EFBE0 {
    char m_pad0[0x10];
    unsigned char* m_p;
    void* m14;
    int m18;
    Entry_001EFBE0* m1C;
    char m_pad20[0x14];
    Entry_001EFBE0* m34;
    void SkipBlock();
};

void Parser_001EFBE0::SkipBlock()
{
    int depth = 0;
    bool going = true;
    do {
        switch (*m_p) {
        case 0x20:
            depth++;
            break;
        case 0x21:
            if (depth != 0)
                depth--;
            else
                going = false;
            break;
        }
        m_p = func_001EB070(m_p);
    } while (going);
    func_001E6B30(m14);
    m_p = func_001ED6B8(m14, m_p, 0);
    if (m1C == m34)
        m1C = 0;
    else
        m1C--;
}
