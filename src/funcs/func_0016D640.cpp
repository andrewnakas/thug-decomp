/* Static-init for two arrays of rows (0x80 rows of 4 elements, 0xC rows of 5) whose element constructors are
   empty: placement-constructs both, leaving only the count-down loops. */
inline void* operator new[](unsigned int, void* p) { return p; }

struct Elem_0016D640 {
    Elem_0016D640() {}
    int m0;
};

struct RowA_0016D640 {
    Elem_0016D640 m_elems[4];
    RowA_0016D640() {}
};

struct RowB_0016D640 {
    Elem_0016D640 m_elems[5];
    RowB_0016D640() {}
};

extern RowA_0016D640 g_tableA_0016D640[0x80];
extern RowB_0016D640 g_tableB_0016D640[0xC];

void func_0016D640(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        new (g_tableA_0016D640) RowA_0016D640[0x80];
        new (g_tableB_0016D640) RowB_0016D640[0xC];
    }
}
