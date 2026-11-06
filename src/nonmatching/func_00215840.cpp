/* fuzzy: 85.7 */
// nm: 6 words: register choice of the first loads (D_00392068 in v1/m160 in v0 in game; swapped here); loop/structure match
struct Node_00215840 {
    int m0;
    int m4;
    int m8;
    Node_00215840* mC;
    Node_00215840* Valid() { return ~m4 ? this : 0; }
};

struct Mgr_00215840 {
    char m_pad0[0x3C];
    Node_00215840* m3C;
};

struct Game_00215840 {
    char m_pad0[0x160];
    int m160;
};

extern Game_00215840* D_00392068;
extern Mgr_00215840* D_0038FC78;
extern "C" int func_00215778(int a, int b);

bool Cmd_00215840(void* params, void* script)
{
    if (D_00392068->m160) {
        Node_00215840* p = D_0038FC78->m3C;
        int n = 0;
        Node_00215840* q;
        while ((q = p->Valid()) != 0) {
            n++;
            p = q->mC;
        }
        if (n || func_00215778(0, 0)) return true;
    }
    return false;
}
