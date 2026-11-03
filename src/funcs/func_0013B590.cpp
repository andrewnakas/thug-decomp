extern "C" int func_001E8A30(void* params, unsigned int name, void* out, int req);
extern "C" void func_0013B330(int mode);

bool Cmd_0013B590(void* params, void* script)
{
    unsigned int crc;
    func_001E8A30(params, 0, &crc, 1);
    switch (crc) {
    case 0x6F70EA65:
        func_0013B330(0);
        break;
    case 0x9B62E5A6:
        func_0013B330(1);
        break;
    case 0xB07B580E:
        func_0013B330(2);
        break;
    case 0xB6624A73:
        func_0013B330(3);
        break;
    case 0x6F2D1231:
        func_0013B330(4);
        break;
    case 0xF624438B:
        func_0013B330(5);
        break;
    }
    return true;
}
