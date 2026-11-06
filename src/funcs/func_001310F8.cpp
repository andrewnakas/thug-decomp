struct Slot_001310F8 {
    char pad[0x18];
    int m18;
};

extern Slot_001310F8 D_003BE920[16];
extern char D_003BEAE0[];
extern "C" void func_00131050(void* self, int n);

/* static initialisation: clears the 16 slots, then constructs the object at D_003BEAE0 */
extern "C" void func_001310F8(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        Slot_001310F8* s = D_003BE920;
        for (int n = 15; n != -1; n--) {
            s->m18 = 0;
            s++;
        }
        func_00131050(D_003BEAE0, 4);
    }
}
