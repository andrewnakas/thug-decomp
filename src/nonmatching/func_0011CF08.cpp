/* fuzzy: 68.2 */
/* blocked: register/schedule tie. The game allocates the end pointer to $v0 and keeps both sq before the
   pointer bump (0x0011CF18-20); index, struct-copy and declaration-order forms and cxxperm do not. */
typedef int qword __attribute__((mode(TI)));

struct Q_0011CF08 {
    qword a;
    qword b;
};

struct Obj_0011CF08 {
    char pad[0x20];
    Q_0011CF08 m_rows[64];
    bool Copy(Q_0011CF08* dst);
};

bool Obj_0011CF08::Copy(Q_0011CF08* dst)
{
    Q_0011CF08* src = m_rows;
    Q_0011CF08* end = m_rows + 64;
    // game: no pre-test, end pointer at this+0x820 compared with bne -> do/while over pointers
    do {
        qword a = src->a;
        qword b = src->b;
        dst->a = a;
        dst->b = b;
        src++;
        dst++;
    } while (src != end);
    return true;
}
