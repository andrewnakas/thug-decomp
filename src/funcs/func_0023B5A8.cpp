struct Array_0023B5A8 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

extern void* D_0038FC78;
extern char D_003737E8[];
extern char D_0038FF18[];

extern "C" void* func_0022E358(void* game);
extern "C" void* func_0022E050(void* game);
extern "C" int func_0024F908(void* mode, unsigned int name);
extern "C" bool func_00215F50(int a, int b);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void* func_001046B0(int size);
extern "C" void* func_0024B140(void* mem, void* params);
extern "C" void* func_0024B740(void* mem, void* params);
extern "C" void* func_0024BB38(void* mem, void* params);
extern "C" void* func_0024A020(void* mem, void* params);
extern "C" void* func_0024A4D0(void* mem, void* params);
extern "C" void* func_0024BE30(void* mem, void* params);
extern "C" void* func_0024E140(void* mem, void* params);
extern "C" void* func_0024E410(void* mem, void* params);
extern "C" void* func_0024E6F0(void* mem, void* params);
extern "C" void* func_0024EBD8(void* mem, void* params);
extern "C" void* func_00243DB8(void* mem, void* params);
extern "C" void func_00243B30(void* table, const unsigned int& key, void* item);
static inline void PutGoal_0023B5A8(void* table, unsigned int key, void* item)
{
    func_00243B30(table, key, item);
}
extern "C" void func_00248788(void* goal);
extern "C" void* func_00244528(void* goal);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_0023B5A8** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" unsigned int func_001E9300(Array_0023B5A8* array, int index);
extern "C" void func_0023FF40(void* self, unsigned int id, unsigned int name);
extern "C" void func_00244208(void* goal, unsigned int name);
extern "C" void func_001E70C0(void* params, unsigned int name, const char* value);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" void* func_001E5548(unsigned int name, int create);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_00262990(void* p);
extern "C" unsigned int func_00262388(void* p);
extern "C" const char* func_001E5488(unsigned int name, int required);

bool func_0023B5A8(char* self, unsigned int id, void* params)
{
    void* game = D_0038FC78;
    int flag = func_0024F908(func_0022E358(game), 0x337E7779);
    if (!func_00215F50(0, 0) && flag && !func_001E8708(params, 0x6BAE094C)) {
        return false;
    }
    if (func_0024F908(func_0022E358(game), 0x353961D7) && !func_001E8708(params, 0x981D3AD0)) {
        return false;
    }
    func_001E7360(params, 0x9982E501, id);
    if (func_001E8708(params, 0xC18FEF36) && func_00215F50(0, 0)) {
        return false;
    }

    void* goal;
    if (func_001E8708(params, 0x4AF5D34E)) {
        goal = func_0024B140(func_001046B0(0xB8), params);
    } else if (func_001E8708(params, 0x0D15EA00)) {
        goal = func_0024B740(func_001046B0(0xA8), params);
    } else if (func_001E8708(params, 0x25904450)) {
        goal = func_0024BB38(func_001046B0(0xA4), params);
    } else if (func_001E8708(params, 0x6BAE094C)) {
        goal = func_0024A020(func_001046B0(0xAC), params);
    } else if (func_001E8708(params, 0x8CFEE956)) {
        goal = func_0024A4D0(func_001046B0(0xD4), params);
    } else if (func_001E8708(params, 0x4147922B)) {
        goal = func_0024BE30(func_001046B0(0x55C), params);
    } else if (func_001E8708(params, 0x9D65D0E7)) {
        goal = func_0024E140(func_001046B0(0xA4), params);
    } else if (func_001E8708(params, 0xC5EC08E6)) {
        goal = func_0024E410(func_001046B0(0xA8), params);
    } else if (func_001E8708(params, 0x7DBB41DD)) {
        goal = func_0024E6F0(func_001046B0(0xBC), params);
    } else if (func_001E8708(params, 0x8E6014F6)) {
        goal = func_0024EBD8(func_001046B0(0xA4), params);
    } else {
        goal = func_00243DB8(func_001046B0(0xA4), params);
    }

    PutGoal_0023B5A8(self + 4, id, goal);
    func_00248788(goal);
    void* goal_params = func_00244528(goal);
    Array_0023B5A8* links;
    if (func_001E8248(goal_params, 0x5E684E45, &links, 0)) {
        int num = links->m_size;
        for (int i = 0; i < num; i++) {
            func_0023FF40(self, id, func_001E9300(links, i));
            func_00244208(goal, func_001E9300(links, i));
        }
    } else {
        unsigned int link;
        if (func_001E8398(goal_params, 0xDD4CABD6, &link, 0)) {
            func_0023FF40(self, id, link);
            func_00244208(goal, link);
        }
    }

    if (func_00215F50(0, 0)) {
        func_001E70C0(func_00244528(goal), 0x944B2900, D_003737E8);
        func_001E70C0(func_00244528(goal), 0x243B9C3B, D_0038FF18);
    } else {
    const char* name;
    if (func_001E7C80(func_00244528(goal), 0x944B2900, &name, 0)) {
        void* info = func_001E5548(0x621D1828, 0);
        unsigned int value;
        if (func_001E8398(info, func_001F0D78(name), &value, 0)
            && func_00262388(func_00262990(func_0022E050(D_0038FC78))) == value) {
            const char* judge = func_001E5488(0x2245B93C, 1);
            func_001E70C0(func_00244528(goal), 0x944B2900, judge);
            const char* title = func_001E5488(0xFE6EF7B8, 1);
            func_001E70C0(func_00244528(goal), 0x243B9C3B, title);
        }
    }
    }
    return goal != 0;
}
