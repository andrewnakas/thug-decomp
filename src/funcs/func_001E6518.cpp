struct Array_001E6518 {
    int m0;
    int m4;
    unsigned int m8;
    unsigned int mC;
};

extern "C" void** func_001E9038(Array_001E6518*);
extern "C" void func_001E4E58(void*);
extern "C" void func_001E8AC0(void*);
extern "C" void func_001E8B70(void*);
extern "C" void func_001E6AE8(void*, int);
extern "C" void func_001E8DE8(void*, int);
extern "C" void func_001E8E38(Array_001E6518*);

extern "C" void func_001E6518(Array_001E6518* a)
{
    unsigned int type = a->m8;
    unsigned int n = a->mC;
    void** d = func_001E9038(a);
    switch (type) {
    case 0:
        break;
    case 13:
        break;
    case 3:
    case 4:
        {
        void** q = d;
        for (unsigned int i = 0; i < n; i++) {
            if (*q) {
                func_001E4E58(*q);
                *q = 0;
            }
            q++;
        }
        }
        break;
    case 5:
        {
        void** q = d;
        for (unsigned int i = 0; i < n; i++) {
            if (*q) {
                func_001E8AC0(*q);
                *q = 0;
            }
            q++;
        }
        }
        break;
    case 6:
        {
        void** q = d;
        for (unsigned int i = 0; i < n; i++) {
            if (*q) {
                func_001E8B70(*q);
                *q = 0;
            }
            q++;
        }
        }
        break;
    case 10:
        {
        void** q = d;
        for (unsigned int i = 0; i < n; i++) {
            if (*q) {
                func_001E6AE8(*q, 3);
                *q = 0;
            }
            q++;
        }
        }
        break;
    case 12:
        {
        void** q = d;
        for (unsigned int i = 0; i < n; i++) {
            if (*q) {
                func_001E6518((Array_001E6518*)*q);
                if (*q)
                    func_001E8DE8(*q, 3);
                *q = 0;
            }
            q++;
        }
        }
        break;
    }
    func_001E8E38(a);
}
