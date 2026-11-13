struct Array_0021BFB0 {
    int pad[3];
    unsigned int m_size;
};

struct Skate_0021BFB0 {
    char pad[0x3AC];
    unsigned int m3AC;
};

extern Skate_0021BFB0* D_0038FC78;
extern char D_00371600[];
extern char D_003715C0[];
extern char D_0038F7E8[];

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" Array_0021BFB0* func_001E55B8(unsigned int name, int assert_);
extern "C" void* func_001E9378(void* self, unsigned int index);
extern "C" bool func_001E6B90(void* self, unsigned int name);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" bool func_001E8618(void* self, unsigned int name);
extern "C" bool func_001E89F0(void* self, unsigned int name, void** out, int assert_);
extern "C" bool func_001E8A30(void* self, unsigned int name, unsigned int* out, int assert_);
extern "C" void func_001E93D0(void* self, int v);
extern "C" int func_001E5648(const char* name, int assert_);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_001E5548(unsigned int name, int assert_);
extern "C" void* func_00121AB0(unsigned int name, unsigned int id, int v);
extern "C" bool func_001E7DE8(void* self, unsigned int name, int* out, int assert_);
extern "C" void func_00121B48(unsigned int name, unsigned int type, void** list, int* count);
extern "C" int func_00100030(int n);

bool func_0021BFB0(void* params)
{
    void* list[64];
    unsigned int name;
    void* sub;
    unsigned int type;
    unsigned int prof;
    void* entry;
    unsigned int id;
    int num;
    int cnt;
    int val;

    func_001E8398(params, 0xB6F08F39, &name, 1);
    Array_0021BFB0* peds = func_001E55B8(name, 1);
    unsigned int n = peds->m_size;
    unsigned int skater = D_0038FC78->m3AC;
    for (unsigned int i = 0; i < n; i++) {
        void* p = func_001E9378(peds, i);
        func_001E6B90(p, 0x355F9467);
        func_001E7200(p, 0xF1E3CD22, 0);
        func_001E7200(p, 0x92BDDFD9, 0);
        func_001E7200(p, 0x4B833E64, -1);
    }
    int count = 0;
    for (unsigned int j = 0; j < n; j++) {
        void* p = func_001E9378(peds, j);
        bool ok = true;
        if (func_001E8618(p, 0xF6F8E158)) {
            ok = false;
            if (func_001E89F0(p, 0x3598BF7D, &sub, 0))
                func_001E93D0(p, 0);
        } else if (func_001E89F0(p, 0x3598BF7D, &sub, 0)) {
            ok = func_001E8618(sub, skater);
        } else if (func_001E89F0(p, 0x94D12F97, &sub, 0)) {
            ok = !func_001E8618(sub, skater);
        }
        if (ok) {
            count++;
            func_001E7200(p, 0x355F9467, 1);
        } else {
            func_001E7200(p, 0x355F9467, 0);
            func_001E5648(D_00371600, 0);
        }
    }
    Array_0021BFB0* nodes = func_001E55B8(0xC472ECC5, 0);
    for (unsigned int k = 0; k < nodes->m_size; k++) {
        void* node = func_001E9378(nodes, k);
        type = 0;
        func_001E8398(node, func_001F0D78(D_0038F7E8), &type, 0);
        if (type == func_001F0D78(D_003715C0) && func_001E8A30(node, 0x7EA855F0, &prof, 0)) {
            void* s = func_001E5548(prof, 0);
            if (s && func_001E89F0(s, name, &entry, 0) && func_001E8A30(entry, 0x4BB2084E, &id, 0)) {
                void* p = func_00121AB0(name, id, 0);
                if (p && !func_001E8618(p, 0xF6F8E158)) {
                    func_001E5648(D_00371600, 0);
                    func_001E7200(p, 0xF1E3CD22, 1);
                    func_001E7200(p, 0x355F9467, 1);
                    func_001E7200(p, 0x92BDDFD9, 1);
                }
            }
        }
    }
    num = count;
    func_001E7DE8(params, 0x23BC5091, &num, 0);
    if (count < num)
        num = count;
    cnt = 0;
    func_00121B48(name, 0, list, &cnt);
    if (cnt == 0) {
        func_00121B48(name, 0x94E5A308, list, &cnt);
        void* p = list[func_00100030(cnt)];
        func_001E7200(p, 0xF1E3CD22, 1);
        func_001E7200(p, 0x355F9467, 0);
        func_001E7200(p, 0x4B833E64, num - 1);
        num--;
        func_00121B48(name, 0x85AAF0D8, list, &cnt);
        p = list[func_00100030(cnt)];
        func_001E7200(p, 0xF1E3CD22, 1);
        func_001E7200(p, 0x355F9467, 0);
        func_001E7200(p, 0x4B833E64, num - 1);
        num--;
        func_00121B48(name, 0xE4834204, list, &cnt);
        p = list[func_00100030(cnt)];
        func_001E7200(p, 0xF1E3CD22, 1);
        func_001E7200(p, 0x355F9467, 0);
        func_001E7200(p, 0x4B833E64, num - 1);
        num--;
    } else {
        void* p = list[func_00100030(cnt)];
        func_001E7200(p, 0xF1E3CD22, 1);
        func_001E7200(p, 0x355F9467, 0);
        func_001E7200(p, 0x4B833E64, num - 1);
        num--;
    }
    for (int j = 0; j < num; j++) {
        val = 0;
        while (!val) {
            void* q = func_001E9378(peds, func_00100030(n));
            func_001E7DE8(q, 0x355F9467, &val, 1);
            if (val) {
                func_001E7200(q, 0xF1E3CD22, 1);
                func_001E7200(q, 0x355F9467, 0);
                func_001E7200(q, 0x4B833E64, j);
            }
        }
    }
    return true;
}
