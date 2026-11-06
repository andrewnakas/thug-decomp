/* fuzzy: 83.8 */
/* NM 7/37 (from lane 2 draft): only the return-true/false branch polarity of both bit tests is inverted (game cross-jumps the first 'return true' into the last one) */
extern "C" bool func_001E7DE8(void* params, int name, int* out, int assert);
extern "C" bool func_001E0ED8(int a);
extern "C" void func_001E0C20(unsigned long* lo, unsigned long* hi);

bool Cmd_0020E258(void* params, void* script)
{
    int idx = 0;
    func_001E7DE8(params, 0, &idx, 0);
    if (func_001E0ED8(0)) {
        unsigned long lo;
        unsigned long hi;
        func_001E0C20(&lo, &hi);
        if (idx < 64) {
            if (!(int)((lo >> idx) & 1))
                return true;
        } else {
            if (!(int)((hi >> (idx - 64)) & 1))
                return true;
        }
    }
    return false;
}
