/* fuzzy: 70.5 */
/* blocked: gcse PRE copies the latch's i+1 (and i<<2) into the loop body's blocks, so i stops being a biv and the outer m124C[i] is not strength-reduced as in the game (t0 at 0x1ADDD4); pointer, indexed and declaration variants all keep the PRE */
struct Entry_001ADDC8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

struct Obj_001ADDC8 {
    char pad[0xA78];
    Entry_001ADDC8 mA78[100];
    int m1248;
    int m124C[1];
    void Method(int id);
};

void Obj_001ADDC8::Method(int id)
{
    for (int i = 0; i < m1248; i++) {
        if (m124C[i] == id) {
            int* p = &m124C[i];
            for (int j = i; j < m1248 - 1; j++) {
                p[0] = p[1];
                p++;
            }
            m1248--;
        }
    }
    for (int k = 0; k < 100; k++)
        if (mA78[k].m0 == id)
            mA78[k].m0 = 0;
}
