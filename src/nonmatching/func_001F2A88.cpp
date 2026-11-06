/* fuzzy: 68.4 */
/* NM 44/58 (lane 2 draft): game puts the success block first and jumps to the loop test at entry (b); for(;;)/while/goto shapes tried */
struct Paren_001F2A88 {
    int m_open;
    int m4;
};

struct Expr_001F2A88 {
    int m0;
    char m_result[0x144 - 0x4];
    int m_num_ops;
    int m_num_values;
    Paren_001F2A88 m_parens[19];
    int pad1E4;
    int m_depth;
    char pad1EC[0x1F4 - 0x1EC];
    int m_error;
    bool Finish(void* out);
};

extern "C" void func_001F13F8(Expr_001F2A88* e, char* msg);
extern "C" void func_001F1478(Expr_001F2A88* e);
extern "C" void func_001E6360(void* dst, char* src);
extern "C" void func_001E6250(char* p);

extern char D_00366078[];
extern char D_00366098[];

bool Expr_001F2A88::Finish(void* out)
{
    for (;;) {
        if (m_parens[m_depth].m_open) {
            func_001F13F8(this, D_00366078);
            return false;
        }
        if (!m_num_ops) {
            if (m_num_values || m_depth) {
                func_001F13F8(this, D_00366098);
                return false;
            }
            func_001E6360(out, m_result);
            func_001E6250(m_result);
            return true;
        }
        func_001F1478(this);
        if (m_error) {
            return false;
        }
    }
}
