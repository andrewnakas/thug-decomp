extern "C" int func_00331950(const char* a, const char* b);

struct Entry_001091B0 {
    char name[0x44];
};

struct Obj_001091B0 {
    char pad[0x20];
    Entry_001091B0 m_entries[1];
    char pad64[0x23C - 0x64];
    int m23C;
    int IsUnique(const char* name);
};

int Obj_001091B0::IsUnique(const char* name)
{
    for (int i = 0; i < m23C; i++) {
        if (func_00331950(m_entries[i].name, name) == 0) {
            return 0;
        }
    }
    return 1;
}
