struct Vec3_001F1478 {
    int m_0;
    float x;
    float y;
    float z;
};

struct Vec2_001F1478 {
    int m_0;
    float x;
    float y;
};

struct Array_001F1478 {
    char m_pad[0x8];
    int m_type;
    unsigned int m_size;
};

struct Comp_001F1478 {
    char m_0;
    unsigned char m_type;
    unsigned short m_2;
    unsigned int m_name;
    union {
        int i;
        float f;
        void* p;
        char* s;
        Vec3_001F1478* v3;
        Vec2_001F1478* v2;
        Array_001F1478* arr;
    };
};

struct Val_001F1478 {
    char m_0;
    unsigned char m_type;
    unsigned short m_2;
    unsigned int m_name;
    union {
        int i;
        float f;
        void* p;
        char* s;
        Vec3_001F1478* v3;
        Vec2_001F1478* v2;
        Array_001F1478* arr;
    };
    int m_C;
};

struct Op_001F1478 {
    int op;
    int paren;
};

struct Eval_001F1478 {
    int m_0;
    Val_001F1478 m_stack[20];
    int m_count;
    Op_001F1478 m_ops[20];
    int m_opTop;
    int m_1EC;
};

extern Val_001F1478 D_003F33E8;
extern char D_003657A0[];
extern char D_003657D0[];
extern char D_003657F0[];
extern char D_00365818[];
extern char D_00365848[];
extern char D_00365870[];
extern char D_003658A0[];
extern char D_003658C8[];
extern char D_003658F0[];
extern char D_00365918[];
extern char D_00365940[];
extern char D_00365970[];
extern char D_003659A0[];
extern char D_003659E0[];
extern char D_00365A08[];
extern char D_00365A38[];
extern char D_00365A68[];
extern char D_00365A98[];
extern char D_00365AC8[];
extern char D_00365B20[];
extern char D_00365B80[];
extern char D_00365BA8[];
extern char D_00365BD8[];
extern char D_00365C08[];
extern char D_00365C38[];
extern char D_00365C60[];
extern char D_00365C90[];
extern char D_00365CB0[];
extern char D_00365CC8[];
extern char D_00365CF0[];
extern char D_00365D18[];
extern char D_00365D40[];
extern char D_00365D68[];
extern char D_00365D90[];
extern char D_00365DC8[];
extern char D_00365E00[];
extern char D_00365E38[];
extern char D_00365E60[];
extern char D_00365E98[];
extern char D_00365EB8[];
extern char D_00365ED0[];
extern char D_00365F00[];

extern "C" void func_001F13F8(Eval_001F1478* self, char* msg);
extern "C" int func_001F1430(Val_001F1478* v);
extern "C" int func_001EA928(Val_001F1478* a, Val_001F1478* b);
extern "C" int func_001EAB70(Val_001F1478* a, Val_001F1478* b);
extern "C" int func_001EACB0(Val_001F1478* a, Val_001F1478* b);
extern "C" void func_001EADF0(Array_001F1478* arr, int index, Val_001F1478* out);
extern "C" void* func_001E8C80(int size);
extern "C" Vec3_001F1478* func_001E4C68(void* mem);
extern "C" void* func_001E8C30(int size);
extern "C" Vec2_001F1478* func_001E4C80(void* mem);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6B90(void* s, unsigned int name);
extern "C" void func_001E6D18(void* s, unsigned int name);
extern "C" void func_001E6C60(void* s, unsigned int name, unsigned char type);
extern "C" Comp_001F1478* func_001E6E90(void* s, Comp_001F1478* prev);
extern "C" Comp_001F1478* func_001E6DD0(void* s, unsigned int name);
extern "C" void func_001E6360(Val_001F1478* d, Comp_001F1478* s);
extern "C" void func_001E6250(Val_001F1478* v);
extern "C" int func_001E9300(Array_001F1478* a, unsigned int i);
extern "C" unsigned int func_00331BB8(char* s);
extern "C" char* func_00331A9C(char* d, char* s);
extern "C" char* func_00331678(char* d, char* s);
extern "C" char* func_001E4DE0(char* s);

extern "C" void func_001F1478(Eval_001F1478* self)
{
    int n = self->m_count;
    if (n <= 0) {
        func_001F13F8(self, D_003657A0);
        return;
    }
    if (self->m_ops[self->m_opTop].paren) {
        func_001F13F8(self, D_003657D0);
        return;
    }
    int op = self->m_ops[self->m_opTop].op;
    if (!op) {
        func_001F13F8(self, D_003657F0);
        return;
    }
    Val_001F1478* a = &self->m_stack[n - 1];
    Val_001F1478* b = &self->m_stack[n];
    D_003F33E8.m_type = 0;
    D_003F33E8.i = 0;

    switch (op) {
    case 50:
        D_003F33E8.m_type = 1;
        D_003F33E8.i = func_001F1430(a) | func_001F1430(b);
        break;
    case 51:
        D_003F33E8.m_type = 1;
        D_003F33E8.i = func_001F1430(a) & func_001F1430(b);
        break;
    case 7:
        D_003F33E8.m_type = 1;
        D_003F33E8.i = func_001EA928(a, b);
        break;
    case 18:
        D_003F33E8.m_type = 1;
        D_003F33E8.i = func_001EAB70(a, b);
        break;
    case 20:
        D_003F33E8.m_type = 1;
        D_003F33E8.i = func_001EACB0(a, b);
        break;
    case 11:
        switch (a->m_type) {
        case 1:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 1;
                D_003F33E8.i = a->i + b->i;
            } else if (b->m_type == 2) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = (float)a->i + b->f;
            } else {
                func_001F13F8(self, D_00365818);
            }
            break;
        case 2:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = a->f + (float)b->i;
            } else if (b->m_type == 2) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = a->f + b->f;
            } else {
                func_001F13F8(self, D_00365848);
            }
            break;
        case 13:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 13;
                D_003F33E8.i = a->i + b->i;
            } else {
                func_001F13F8(self, D_00365870);
            }
            break;
        case 6:
            if (b->m_type == 6) {
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = a->v3->x + b->v3->x;
                D_003F33E8.v3->y = a->v3->y + b->v3->y;
                D_003F33E8.v3->z = a->v3->z + b->v3->z;
            } else {
                func_001F13F8(self, D_003658A0);
            }
            break;
        case 5:
            if (b->m_type == 5) {
                D_003F33E8.m_type = 5;
                D_003F33E8.v2 = func_001E4C80(func_001E8C30(0xC));
                D_003F33E8.v2->x = a->v2->x + b->v2->x;
                D_003F33E8.v2->y = a->v2->y + b->v2->y;
            } else {
                func_001F13F8(self, D_003658C8);
            }
            break;
        case 3:
            if (b->m_type == 3) {
                if (func_00331BB8(a->s) + func_00331BB8(b->s) + 1 <= 200) {
                    char buf[200];
                    D_003F33E8.m_type = 3;
                    func_00331A9C(buf, a->s);
                    func_00331678(buf, b->s);
                    D_003F33E8.s = func_001E4DE0(buf);
                } else {
                    func_001F13F8(self, D_003658F0);
                }
            } else {
                func_001F13F8(self, D_00365918);
            }
            break;
        case 4:
            if (b->m_type == 4) {
                if (func_00331BB8(a->s) + func_00331BB8(b->s) + 1 > 200) {
                    func_001F13F8(self, D_00365940);
                } else {
                    char buf[200];
                    D_003F33E8.m_type = 4;
                    func_00331A9C(buf, a->s);
                    func_00331678(buf, b->s);
                    D_003F33E8.s = func_001E4DE0(buf);
                }
            } else {
                func_001F13F8(self, D_00365970);
            }
            break;
        case 10:
            if (b->m_type != 10) {
                func_001F13F8(self, D_003659A0);
                break;
            }
            D_003F33E8.m_type = 10;
            D_003F33E8.p = func_001E6978(func_001190D0(8));
            func_001E6AC8(D_003F33E8.p, a->p);
            func_001E6AC8(D_003F33E8.p, b->p);
            break;
        case 7:
        case 8:
        case 9:
        case 11:
        case 12:
        default:
            func_001F13F8(self, D_003659E0);
            break;
        }
        break;
    case 10:
        switch (a->m_type) {
        case 1:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 1;
                D_003F33E8.i = a->i - b->i;
            } else if (b->m_type == 2) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = (float)a->i - b->f;
            } else {
                func_001F13F8(self, D_00365A08);
            }
            break;
        case 2:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = a->f - (float)b->i;
            } else if (b->m_type == 2) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = a->f - b->f;
            } else {
                func_001F13F8(self, D_00365A38);
            }
            break;
        case 6:
            if (b->m_type == 6) {
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = a->v3->x - b->v3->x;
                D_003F33E8.v3->y = a->v3->y - b->v3->y;
                D_003F33E8.v3->z = a->v3->z - b->v3->z;
            } else {
                func_001F13F8(self, D_00365A68);
            }
            break;
        case 5:
            if (b->m_type == 5) {
                D_003F33E8.m_type = 5;
                D_003F33E8.v2 = func_001E4C80(func_001E8C30(0xC));
                D_003F33E8.v2->x = a->v2->x - b->v2->x;
                D_003F33E8.v2->y = a->v2->y - b->v2->y;
            } else {
                func_001F13F8(self, D_00365A98);
            }
            break;
        case 10:
            if (b->m_type == 13) {
                D_003F33E8.m_type = 10;
                D_003F33E8.p = func_001E6978(func_001190D0(8));
                func_001E6AC8(D_003F33E8.p, a->p);
                func_001E6B90(D_003F33E8.p, b->i);
                func_001E6D18(D_003F33E8.p, b->i);
            } else if (b->m_type == 12) {
                Array_001F1478* arr = b->arr;
                if (arr->m_type != 13 && arr->m_type != 0) {
                    func_001F13F8(self, D_00365AC8);
                    break;
                }
                D_003F33E8.m_type = 10;
                D_003F33E8.p = func_001E6978(func_001190D0(8));
                func_001E6AC8(D_003F33E8.p, a->p);
                for (unsigned int i = 0; i < arr->m_size; i++) {
                    func_001E6B90(D_003F33E8.p, func_001E9300(arr, i));
                    func_001E6D18(D_003F33E8.p, func_001E9300(arr, i));
                }
            } else if (b->m_type == 10) {
                D_003F33E8.m_type = 10;
                D_003F33E8.p = func_001E6978(func_001190D0(8));
                func_001E6AC8(D_003F33E8.p, a->p);
                void* s = b->p;
                Comp_001F1478* c = func_001E6E90(s, 0);
                while (c) {
                    if (c->m_name) {
                        func_001E6C60(D_003F33E8.p, c->m_name, c->m_type);
                    } else if (c->m_type == 13) {
                        func_001E6B90(D_003F33E8.p, c->i);
                        func_001E6D18(D_003F33E8.p, c->i);
                    }
                    c = func_001E6E90(s, c);
                }
            } else {
                func_001F13F8(self, D_00365B20);
            }
            break;
        case 3:
        case 4:
        case 7:
        case 8:
        case 9:
        default:
            func_001F13F8(self, D_00365B80);
            break;
        }
        break;
    case 13:
        switch (a->m_type) {
        case 1:
            switch (b->m_type) {
            case 1:
                D_003F33E8.m_type = 1;
                D_003F33E8.i = a->i * b->i;
                break;
            case 2:
                D_003F33E8.m_type = 2;
                D_003F33E8.f = (float)a->i * b->f;
                break;
            case 6:
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = (float)a->i * b->v3->x;
                D_003F33E8.v3->y = (float)a->i * b->v3->y;
                D_003F33E8.v3->z = (float)a->i * b->v3->z;
                break;
            case 5:
                D_003F33E8.m_type = 5;
                D_003F33E8.v2 = func_001E4C80(func_001E8C30(0xC));
                D_003F33E8.v2->x = (float)a->i * b->v2->x;
                D_003F33E8.v2->y = (float)a->i * b->v2->y;
                break;
            default:
                func_001F13F8(self, D_00365BA8);
                break;
            }
            break;
        case 2:
            switch (b->m_type) {
            case 1:
                D_003F33E8.m_type = 2;
                D_003F33E8.f = a->f * (float)b->i;
                break;
            case 2:
                D_003F33E8.m_type = 2;
                D_003F33E8.f = a->f * b->f;
                break;
            case 6:
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = a->f * b->v3->x;
                D_003F33E8.v3->y = a->f * b->v3->y;
                D_003F33E8.v3->z = a->f * b->v3->z;
                break;
            case 5:
                D_003F33E8.m_type = 5;
                D_003F33E8.v2 = func_001E4C80(func_001E8C30(0xC));
                D_003F33E8.v2->x = a->f * b->v2->x;
                D_003F33E8.v2->y = a->f * b->v2->y;
                break;
            default:
                func_001F13F8(self, D_00365BD8);
                break;
            }
            break;
        case 6:
            switch (b->m_type) {
            case 6:
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = a->v3->y * b->v3->z - a->v3->z * b->v3->y;
                D_003F33E8.v3->y = a->v3->z * b->v3->x - a->v3->x * b->v3->z;
                D_003F33E8.v3->z = a->v3->x * b->v3->y - a->v3->y * b->v3->x;
                break;
            case 2:
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = a->v3->x * b->f;
                D_003F33E8.v3->y = a->v3->y * b->f;
                D_003F33E8.v3->z = a->v3->z * b->f;
                break;
            case 1:
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = a->v3->x * (float)b->i;
                D_003F33E8.v3->y = a->v3->y * (float)b->i;
                D_003F33E8.v3->z = a->v3->z * (float)b->i;
                break;
            default:
                func_001F13F8(self, D_00365C08);
                break;
            }
            break;
        case 5:
            switch (b->m_type) {
            case 2:
                D_003F33E8.m_type = 5;
                D_003F33E8.v2 = func_001E4C80(func_001E8C30(0xC));
                D_003F33E8.v2->x = a->v2->x * b->f;
                D_003F33E8.v2->y = a->v2->y * b->f;
                break;
            case 1:
                D_003F33E8.m_type = 5;
                D_003F33E8.v2 = func_001E4C80(func_001E8C30(0xC));
                D_003F33E8.v2->x = a->v2->x * (float)b->i;
                D_003F33E8.v2->y = a->v2->y * (float)b->i;
                break;
            default:
                func_001F13F8(self, D_00365C38);
                break;
            }
            break;
        default:
            func_001F13F8(self, D_00365C60);
            break;
        }
        break;
    case 12: {
        if (b->m_type == 1) {
            if (!b->i) {
                func_001F13F8(self, D_00365C90);
                break;
            }
        } else if (b->m_type == 2) {
            if (b->f == 0.0f) {
                func_001F13F8(self, D_00365CB0);
                break;
            }
        }
        switch (a->m_type) {
        case 1:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 1;
                D_003F33E8.i = a->i / b->i;
            } else if (b->m_type == 2) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = (float)a->i / b->f;
            } else {
                func_001F13F8(self, D_00365CC8);
            }
            break;
        case 2:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = a->f / (float)b->i;
            } else if (b->m_type == 2) {
                D_003F33E8.m_type = 2;
                D_003F33E8.f = a->f / b->f;
            } else {
                func_001F13F8(self, D_00365CF0);
            }
            break;
        case 6:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = a->v3->x / (float)b->i;
                D_003F33E8.v3->y = a->v3->y / (float)b->i;
                D_003F33E8.v3->z = a->v3->z / (float)b->i;
            } else if (b->m_type == 2) {
                D_003F33E8.m_type = 6;
                D_003F33E8.v3 = func_001E4C68(func_001E8C80(0x10));
                D_003F33E8.v3->x = a->v3->x / b->f;
                D_003F33E8.v3->y = a->v3->y / b->f;
                D_003F33E8.v3->z = a->v3->z / b->f;
            } else {
                func_001F13F8(self, D_00365D18);
            }
            break;
        case 5:
            if (b->m_type == 1) {
                D_003F33E8.m_type = 5;
                D_003F33E8.v2 = func_001E4C80(func_001E8C30(0xC));
                D_003F33E8.v2->x = a->v2->x / (float)b->i;
                D_003F33E8.v2->y = a->v2->y / (float)b->i;
            } else if (b->m_type == 2) {
                D_003F33E8.m_type = 5;
                D_003F33E8.v2 = func_001E4C80(func_001E8C30(0xC));
                D_003F33E8.v2->x = a->v2->x / b->f;
                D_003F33E8.v2->y = a->v2->y / b->f;
            } else {
                func_001F13F8(self, D_00365D40);
            }
            break;
        default:
            func_001F13F8(self, D_00365D68);
            break;
        }
        break;
    }
    case 8:
        switch (a->m_type) {
        case 6:
            if (b->m_type != 6) {
                func_001F13F8(self, D_00365D90);
                break;
            }
            D_003F33E8.m_type = 2;
            D_003F33E8.f = a->v3->x * b->v3->x + a->v3->y * b->v3->y + a->v3->z * b->v3->z;
            break;
        case 5:
            if (b->m_type != 5) {
                func_001F13F8(self, D_00365DC8);
                break;
            }
            D_003F33E8.m_type = 2;
            D_003F33E8.f = a->v2->x * b->v2->x + a->v2->y * b->v2->y;
            break;
        case 10:
            if (b->m_type != 13) {
                func_001F13F8(self, D_00365E00);
                break;
            }
            {
                Comp_001F1478* c = func_001E6DD0(a->p, b->i);
                if (c) {
                    func_001E6360(&D_003F33E8, c);
                }
            }
            break;
        default:
            func_001F13F8(self, D_00365E38);
            break;
        }
        break;
    case 5:
        if (a->m_type != 12) {
            func_001F13F8(self, D_00365E60);
            break;
        }
        if (b->m_type != 1) {
            func_001F13F8(self, D_00365E98);
            break;
        }
        if ((unsigned int)b->i >= a->arr->m_size) {
            func_001F13F8(self, D_00365EB8);
            break;
        }
        func_001EADF0(a->arr, b->i, &D_003F33E8);
        if (!D_003F33E8.m_type) {
            func_001F13F8(self, D_00365ED0);
        }
        break;
    case 6:
    case 9:
    case 14:
    case 15:
    case 16:
    case 17:
    case 19:
    default:
        func_001F13F8(self, D_00365F00);
        break;
    }

    func_001E6250(a);
    func_001E6250(b);
    a->m_type = D_003F33E8.m_type;
    a->i = D_003F33E8.i;
    D_003F33E8.m_type = 0;
    D_003F33E8.i = 0;
    self->m_count--;
    self->m_ops[self->m_opTop].op = 0;
    if (self->m_opTop) {
        self->m_opTop--;
    } else {
        self->m_1EC = 0;
    }
}
