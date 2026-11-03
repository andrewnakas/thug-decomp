struct HashTable_00134B50 {
    void Reset();
    void* Next(int* key);
};

struct Info_00134698 {
    char pad[0xC];
    int mC;
};

struct Scene_00134698;

extern "C" void func_001E70C0(void* s, unsigned int key, Scene_00134698* val);
extern "C" void func_001E7200(void* s, unsigned int key, int val);
extern "C" void* func_00134F18(void* m);
extern "C" int func_0013C7E0(void* g);
extern "C" int func_0013C858(void* g);
extern "C" int func_0013C880(void* g);
extern "C" int func_00133D38(Scene_00134698* self);

struct Scene_00134698 {
    char pad0[0x84];
    Info_00134698* m_84;
    char pad88[0x48];
    HashTable_00134B50* m_D0;
    void GetStats(void* s);
};

void Scene_00134698::GetStats(void* s)
{
    int meshes = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    func_001E70C0(s, 0xC3F4169A, this);
    HashTable_00134B50* t = m_D0;
    if (t) {
        t->Reset();
        void* m;
        while ((m = t->Next(0)) != 0) {
            meshes++;
            void* g = func_00134F18(m);
            if (g) {
                a += func_0013C7E0(g);
                b += func_0013C858(g);
                c += func_0013C880(g);
            }
        }
    }
    func_001E7200(s, 0x4A6BF967, meshes);
    func_001E7200(s, 0x0AC30A9D, func_00133D38(this));
    func_001E7200(s, 0x969D3AF6, a);
    func_001E7200(s, 0xD576DF05, b);
    func_001E7200(s, 0x1E3061EE, c);
    func_001E7200(s, 0x5714C480, m_84->mC);
}
