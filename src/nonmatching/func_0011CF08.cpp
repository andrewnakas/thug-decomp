/* fuzzy: 43.5 */
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
    for (int i = 0; i < 64; i++) {
        qword a = m_rows[i].a;
        qword b = m_rows[i].b;
        dst[i].a = a;
        dst[i].b = b;
    }
    return true;
}
