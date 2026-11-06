typedef int qword __attribute__((mode(TI)));

struct Vec_001723A0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_001723A0 {
    Vec_001723A0 r[4];
};

struct Geom_001723A0;

struct Info_001723A0 {
    char pad[0x30];
    int count;
    char pad34[0x3C - 0x34];
    Geom_001723A0* head;
};

struct Geom_001723A0 {
    Mat_001723A0 mat;
    void* m40;
    char pad44[0x60 - 0x44];
    int flags;
    union {
        unsigned int color;
        unsigned int* colors;
    };
    int m68;
    Geom_001723A0* next;
    Info_001723A0* info;
    int m74;
    unsigned char m78;
    unsigned char m79;
    Geom_001723A0(Info_001723A0* i, Mat_001723A0 m, int perVertex);
};

extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

Geom_001723A0::Geom_001723A0(Info_001723A0* i, Mat_001723A0 m, int perVertex)
{
    mat = m;
    flags = 1;
    m40 = 0;
    m68 = 0;
    next = i->head;
    i->head = this;
    m78 = 0;
    m79 = 0;
    info = i;
    m74 = 0;
    if (perVertex) {
        flags |= 0x10;
        colors = (unsigned int*)func_0010A638(D_00388A70, i->count * 4, 1, 0);
        for (int k = 0; k < info->count; k++) {
            colors[k] = 0x80808080;
        }
    } else {
        color = 0x80808080;
    }
}
