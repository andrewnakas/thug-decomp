struct Params_00211478 {
    int id;
    int val;
};

struct Info_00211478 {
    char pad0[0xBC];
    int mBC;
};

struct Mgr_00211478 {
    char pad0[0x28];
    int m28;
};

extern Mgr_00211478* D_0038FC78;
extern char D_003704E8[];
extern "C" int func_001E55B8(unsigned int id, int a);
extern "C" int func_001E9378(int s, int node);
extern "C" int func_001E8398(int s, unsigned int id, unsigned int* v, int f);
extern "C" int func_0022E040(Mgr_00211478* m);
extern "C" void func_00211438();
extern "C" void func_00187900(int obj, void (*cb)(), Params_00211478* p);
extern "C" int func_001E87B8(int s, char* name);
extern "C" void func_00269070(int a, int id, int b, int c);
extern "C" void func_0026BA18(int id, int a);
extern "C" void func_0026C408(int id, int a);
extern "C" int func_00131E48();
extern "C" int func_00132FD0(int a, unsigned int v);
extern "C" void func_00135048(int a, int b);
extern "C" int func_001E8708(int s, unsigned int id);
extern "C" void func_00132078(unsigned int v, int a);

int func_00211478(int id, Info_00211478* info)
{
    Params_00211478 p;
    Mgr_00211478* mgr = D_0038FC78;
    int rail = mgr->m28;
    int s = func_001E9378(func_001E55B8(0xC472ECC5, 0), id);
    unsigned int type = 0;
    func_001E8398(s, 0x12B4E660, &type, 0);
    switch (type) {
    case 0x9E7D469E:
    case 0x19B1E241:
    case 0x061A741E:
    case 0x5B8AB877:
    case 0xA0DFAC98:
    case 0xB7B3BD86:
    case 0xE47F1B79:
    case 0xEF59C100:
        p.id = id;
        p.val = info->mBC;
        func_00187900(func_0022E040(mgr), func_00211438, &p);
        break;
    case 0x30C19600:
        func_00269070(rail, id, 0, func_001E87B8(s, D_003704E8));
        break;
    case 0x8E6B02AD:
        func_00269070(rail, id, 0, func_001E87B8(s, D_003704E8));
        break;
    case 0x08470F2E:
        func_0026BA18(id, 0);
        break;
    case 0xD64DC7C2:
        func_0026C408(id, 0);
        break;
    case 0xBF4D3536: {
        unsigned int v = 0;
        if (func_001E8398(s, 0xA1DC81F9, &v, 0)) {
            func_00135048(func_00132FD0(func_00131E48(), v), 0);
            if (func_001E8708(s, 0x4E549FE1)) func_00132078(v, 0);
        }
        break;
    }
    default:
        return 0;
    }
    return 1;
}
