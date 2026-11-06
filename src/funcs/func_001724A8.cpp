typedef int qword __attribute__((mode(TI)));

struct Vec_001724A8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_001724A8 {
    Vec_001724A8 r[4];
};

struct Geom_001724A8;

struct Info_001724A8 {
    char pad[0x30];
    int count;
    char pad34[0x3C - 0x34];
    Geom_001724A8* head;
};

struct Geom_001724A8 {
    Mat_001724A8 mat;
    void* m40;
    char pad44[0x60 - 0x44];
    int flags;
    union {
        unsigned int color;
        unsigned int* colors;
    };
    int m68;
    Geom_001724A8* next;
    Info_001724A8* info;
    int m74;
    unsigned char m78;
    unsigned char m79;
    Geom_001724A8(Info_001724A8* i, Mat_001724A8 m, int perVertex, int k68, void* p40);
};

extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

Geom_001724A8::Geom_001724A8(Info_001724A8* i, Mat_001724A8 m, int perVertex, int k68, void* p40)
{
    mat = m;
    m40 = p40;
    m68 = k68;
    flags = 1;
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
