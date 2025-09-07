#ifdef LIBWRITEENABLEFORTHREADSATSTACK_EXPORTS
#define LIBWRITEENABLEFORTHREADSATSTACK_API __declspec(dllexport)
#else
#define LIBWRITEENABLEFORTHREADSATSTACK_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	class LIBWRITEENABLEFORTHREADSATSTACK_API Library_WriteEnableForThreadsAt_STACK {
	public:
		Library_WriteEnableForThreadsAt_STACK();
		static void* Initialise_WriteEnable();
		static void Write_End(class WriteEnableForThreadsAt_STACK_Framework* obj, unsigned char coreId);
		static void Write_Start(class WriteEnableForThreadsAt_STACK_Framework* obj, unsigned char coreId);

	private:
		static class WriteEnableForThreadsAt_STACK_Framework* Get_Framework_WriteEnable();
		static void Set_writeEnable(class Avril_FSD::WriteEnableForThreadsAt_STACK_Framework* writeEnable);
	};
}