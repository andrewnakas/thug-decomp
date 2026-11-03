extern char D_00362800[];
extern char D_00362810[];
extern char D_00362820[];
extern char D_00362830[];
extern "C" int func_001AA3B8(void* self);
extern "C" int func_001E7F50(void* self, char* name, void* out, int n);

float Get001AA3F0(void* self)
{
    int t = func_001AA3B8(self);
    float v = 0.0f;
    switch (t) {
    case 1:
        func_001E7F50(self, D_00362800, &v, 1);
        break;
    case 2:
        func_001E7F50(self, D_00362810, &v, 1);
        break;
    case 3:
        func_001E7F50(self, D_00362820, &v, 1);
        break;
    case 0:
    case 4:
    default:
        func_001E7F50(self, D_00362830, &v, 1);
        break;
    }
    return v;
}
