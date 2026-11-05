/* sym: __12Str_00250B30 = 0x00104008 */
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);

struct Str_00250B30 {
    int m0[9];
    Str_00250B30();
};

struct Obj_00250B30 {
    int m0;
    void* m4;
    int m8;
    Str_00250B30 mC[8];
    Obj_00250B30();
};

Obj_00250B30::Obj_00250B30()
{
    m4 = func_001E6978(func_001190D0(8));
}
