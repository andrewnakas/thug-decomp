struct Slot_0024BFE8 {
    char pad[0xC];
    int m_id;
    int m_done;
    char pad14[0x10];
};

class Base_0024BFE8 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool IsActive();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual bool IsPaused();
};

class Goal_0024BFE8 : public Base_0024BFE8 {
public:
    char pad18[0x8];
    void* m_params;
    char pad24[0x30];
    int m54;
    char pad58[0x48];
    int mA0;
    Slot_0024BFE8 m_slots[30];
    int m4DC;
    int m4E0;
};

extern "C" bool func_001E7DE8(void* self, unsigned int name, int* out, int assert_);
extern "C" bool func_0024E048(Goal_0024BFE8* self);
extern "C" bool func_0024E0C0(Goal_0024BFE8* self);
extern "C" bool func_0024DF20(Goal_0024BFE8* self);
extern "C" bool func_0024DFD0(Goal_0024BFE8* self);
extern "C" void* func_00240850();
extern "C" unsigned int func_00246258(Goal_0024BFE8* self);
extern "C" bool func_0023BD18(void* self, unsigned int id);
extern "C" void func_0024DC48(Goal_0024BFE8* self);
extern "C" void func_0024C590(Goal_0024BFE8* self, int n);
extern "C" float func_0010FAB8();
extern "C" bool func_001E8708(void* self, unsigned int name);
extern "C" void func_001E7360(void* self, unsigned int name, unsigned int value);
extern "C" bool func_002451B0(Goal_0024BFE8* self);

bool func_0024BFE8(Goal_0024BFE8* self)
{
    int done;
    int limit;
    int count;
    int target;
    int count2;
    int target2;
    int max;
    int n;
    int time;
    int n2;

    done = 0;
    func_001E7DE8(self->m_params, 0x7824963C, &done, 0);
    if (!done) {
        limit = 1;
        if (!func_0024E048(self) && func_001E7DE8(self->m_params, 0xA6D96603, &limit, 0))
            limit *= 1000;
        if (func_0024E0C0(self)) {
            if (self->IsActive() && !self->IsPaused()) {
                count = 0;
                func_001E7DE8(self->m_params, 0x8D958F01, &count, 0);
                func_001E7DE8(self->m_params, 0xBFD3A831, &target, 1);
                if (count >= target) {
                    func_0023BD18(func_00240850(), func_00246258(self));
                    return true;
                }
            }
        } else if (self->IsActive() && self->m54 < limit && !self->IsPaused() && func_0024DF20(self)) {
            func_0023BD18(func_00240850(), func_00246258(self));
            return true;
        }
        if (self->IsActive() && !self->IsPaused())
            func_0024DC48(self);
        if (func_0024E0C0(self)) {
            if ((self->mA0 || (float)self->m54 > 0.0f) && !self->IsPaused()) {
                count2 = 0;
                func_001E7DE8(self->m_params, 0x8D958F01, &count2, 0);
                int left = 0;
                func_001E7DE8(self->m_params, 0xBFD3A831, &target2, 1);
                for (int i = 0; i < 30; i++) {
                    if (!self->m_slots[i].m_done)
                        left++;
                }
                func_001E7DE8(self->m_params, 0x45A375C9, &max, 1);
                if (left < max && left + count2 < target2) {
                    int a = max - left;
                    int b = target2 - count2 - left;
                    func_0024C590(self, b < a ? b : a);
                }
            }
        } else if (self->IsActive() && (self->mA0 || self->m54 >= limit) && !self->IsPaused()) {
            self->m4E0 += (int)(func_0010FAB8() * 1000.0f);
            if (func_0024E048(self)) {
                if (!func_001E8708(self->m_params, 0xC93DA683) && self->m4E0 >= 51) {
                    func_001E7DE8(self->m_params, 0x67DD90CA, &n, 1);
                    func_0024C590(self, n);
                    func_001E7360(self->m_params, 0, 0xC93DA683);
                }
            } else {
                func_001E7DE8(self->m_params, 0x648D8D2A, &time, 1);
                if (self->m4E0 > time) {
                    self->m4E0 = 0;
                    if (func_0024DFD0(self)) {
                        func_001E7DE8(self->m_params, 0x67DD90CA, &n2, 1);
                        func_0024C590(self, n2);
                    } else {
                        func_0024C590(self, 1);
                    }
                }
            }
        }
    }
    return func_002451B0(self);
}
