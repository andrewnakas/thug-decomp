struct Mgr_00223100 {
    char pad[0x444];
    int m_values[1];
};

extern Mgr_00223100* D_0038FC78;
extern char D_00371B00[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Cmd_00223100(void* params, void* script)
{
    int value;
    int index;
    func_001E7E58(params, D_00371B00, &value, 1);
    func_001E7DE8(params, 0x5B8AB877, &index, 1);
    return D_0038FC78->m_values[index] == value;
}
