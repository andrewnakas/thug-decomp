/* fuzzy: 64.6 */
struct Req_00111278 {
    char pad0[0xC];
    int mC;
    char pad10[0xC];
    int m1C;
};

struct Obj_00111278 {
    char pad0[0x1C];
    volatile int m1C;
    char pad20[8];
    volatile int m28;
    volatile int m2C;
    int m30;
    volatile int m34;
    int m38;
    volatile int m3C;
    char pad40[0x104];
    void* m144;
    void* m148;
    int m14C;
};

extern char D_0035BEA0[];
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);
extern "C" void func_00111F70(int h);
extern "C" int func_0031CD60(const char* fmt, ...);
extern "C" void func_0010E7E8(Obj_00111278* self, int cmd, int result, int id);


extern "C" void func_00111278(Obj_00111278* self, unsigned int cmd, int result, Req_00111278* req)
{
    int id = req->m1C;
    if (cmd == 0)
        return;
    if (cmd == 1) {
        self->m3C = result;
        if (result < 0) {
            self->m28 = 0;
        } else {
            self->m28 = id;
        }
    } else if (cmd == 5) {
        if (result >= 0) self->m2C = result;
    } else if (cmd >= 2 && cmd <= 4) {
        if (cmd != 4 && self->m148 && result > 0) {
            func_00331404(self->m144, self->m148, result);
        }
        if (result >= 0) {
            self->m2C += result;
            if (self->m148) {
                func_00111F70(self->m14C);
                self->m144 = 0;
                self->m148 = 0;
                self->m14C = 0;
            }
        }
    } else if (cmd == 6) {
        if (self->m34 >= 2) {
            func_0031CD60(D_0035BEA0, self->m34 - 1, self, req->mC);
        }
    }
    func_0010E7E8(self, cmd, result, id);
}
