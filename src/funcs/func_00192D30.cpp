/* Static-init: constructs the object at D_003E3570, then placement-constructs a 0x18-element array of objects
   whose constructor is empty (only the count-down loop remains). */
inline void* operator new[](unsigned int, void* p) { return p; }

extern char D_003E3570[];
extern "C" void* func_001DA890(void* self);

struct Elem_00192D30 {
    Elem_00192D30() {}
    int m0;
};

extern Elem_00192D30 g_table_00192D30[0x18];

void func_00192D30(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        func_001DA890(D_003E3570);
        new (g_table_00192D30) Elem_00192D30[0x18];
    }
}
