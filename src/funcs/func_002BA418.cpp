typedef int qword_002BA418 __attribute__((mode(TI)));

union Q_002BA418 {
    qword_002BA418 q;
    struct { float x, y, z, w; } v;
};

struct Box_002BA418 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Entry_002BA418 {
    Q_002BA418 q;
    int c0;
    Box_002BA418 box;
    int key;
    int flag;
};

extern "C" void func_002BA688(void* self, int n, int* a, int* b);

struct Obj_002BA418 {
    char pad0[0xB0];
    Entry_002BA418 entries[1];
    int Add(Q_002BA418* q, int c, Box_002BA418* box, int key, int flag, int reuse);
};

int Obj_002BA418::Add(Q_002BA418* pq, int c, Box_002BA418* pbox, int key, int flag, int reuse)
{
    int lo = 0;
    int hi = 0;
    func_002BA688(this, key, &lo, &hi);
    Q_002BA418 q = *pq;
    Box_002BA418 b = *pbox;
    if (flag && reuse) {
        for (int i = lo; i <= hi; i++) {
            if (entries[i].key == key && entries[i].flag == 0) {
                q = entries[i].q;
                b = entries[i].box;
            }
        }
    }
    for (int i = lo; i <= hi; i++) {
        if (entries[i].key == 0 || (entries[i].flag != 0 && !flag)) {
            entries[i].q = q;
            entries[i].c0 = c;
            entries[i].box = b;
            entries[i].key = key;
            entries[i].flag = flag;
            return 1;
        }
    }
    return 0;
}
