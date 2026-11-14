/* fuzzy: 87.3 */
/* blocked (lane2 b3): game computes &used into $s6 inside the retry loop (block after the first `if (used)`) and keeps 13 and sp+4 un-hoisted there; a do/while retry loop followed by the scan loop hoists everything (98 words), the current for(;;) form hoists only &used. */
/* NEAR MISS (r2 wt2): 42/106, size+frame now right (0x1a8, 0x60, s0-s7). Fixes: loop 2 uses its own index j and
   returns idx (the game's loop 2 'found' returns the last random idx: daddu v0,s2), which also gives the 8th saved reg.
   Left: game computes &used fresh in loop 1 (addiu a2,sp,4) and sets the loop-2 pointer s6=&used in loop 1 after the
   used test; ours hoists &used before loop 1; loop-1 'used' return is cross-jumped into loop 2's return block in the
   game (ours the other way). A do{...}while(0) wrapper (rejected style) gives 31. Previous note: */
/* NEAR MISS: structure right with goto loop (13 not hoisted in loop 1); register allocation differs (game arr s1, i s0, &used only hoisted in loop 2, s7=this; frame 0x60 vs 0x50). */
struct Array_00245FB8 {
    char pad[8];
    int m_type;
    unsigned int m_count;
};

struct Obj_00245FB8 {
    int Pick(Array_00245FB8* arr);
};

extern void* D_0038FC78;
extern "C" void* func_0022E368(void* self, int index);
extern "C" void* func_00262330(void* a, unsigned int name);
extern "C" unsigned int func_00100030(unsigned int n);
extern "C" unsigned int func_001E9300(Array_00245FB8* arr, unsigned int i);
extern "C" void* func_001E9378(Array_00245FB8* arr, unsigned int i);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_00246160(Obj_00245FB8* self);

static inline void GetName_00245FB8(Array_00245FB8* arr, unsigned int i, unsigned int* name)
{
    if (arr->m_type == 13) {
        *name = func_001E9300(arr, i);
    } else {
        func_001E8398(func_001E9378(arr, i), 0xACFDB27A, name, 1);
    }
}

int Obj_00245FB8::Pick(Array_00245FB8* arr)
{
    unsigned int i = 100;
    void* info = func_00262330(func_0022E368(D_0038FC78, 0), 0xD544AA2D);
    unsigned int n = arr->m_count;
    unsigned int name;
    unsigned int used = 0;
    int v;
    unsigned int idx;
    for (;;) {
        idx = func_00100030(n);
        GetName_00245FB8(arr, idx, &name);
        func_001E8398(info, name, &used, 0);
        if (used) {
            return idx;
        }
        if (func_001E7DE8(info, name, &v, 0)) {
            return idx;
        }
        used = 0;
        if (--i == 0) {
            for (unsigned int j = 0; j < n; j++) {
                GetName_00245FB8(arr, j, &name);
                func_001E8398(info, name, &used, 0);
                if (used) {
                    return idx;
                }
                used = 0;
            }
            func_00246160(this);
            return -1;
        }
    }
}
