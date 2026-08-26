#--------------------------------------------------------------------------------
#
# Filename    : Makefile
# Written By  : Reiot
#
#--------------------------------------------------------------------------------

#--------------------------------------------------------------------------------
# Directories
#--------------------------------------------------------------------------------
VSHOME  = ../../../..
STLDIR  = /usr/include/STL
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
SRCDIR  = $(VSHOME)/src
COREDIR = $(VSHOME)/src/Core
SERVDIR = $(VSHOME)/src/server
DBDIR   = $(SERVDIR)/database
GSDIR   = $(SERVDIR)/gameserver
LSDIR   = $(SERVDIR)/loginserver
SSDIR   = $(SERVDIR)/sharedserver
SKILLDIR= $(GSDIR)/skill
ITEMDIR = $(GSDIR)/item
BILLINGDIR = $(GSDIR)/billing


#--------------------------------------------------------------------------------
# General Rules
#--------------------------------------------------------------------------------
.SUFFIXES : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__ -D__GAME_SERVER__ 
INCLUDES = -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(SKILLDIR) -I$(ITEMDIR) -I$(BILLINGDIR)

CCFLAGS  = -Wall -c -g 
#CCFLAGS  = -Wall -c

TARGET_GS  = $(LIBDIR)/libGameServerPackets.a
TARGET_LS  = $(LIBDIR)/libLoginServerPackets.a
TARGET_SS  = $(LIBDIR)/libSharedServerPackets.a

TARGET = $(TARGET_GS)

include ../OBJS

.cpp.o : 
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#--------------------------------------------------------------------------------
# Actions
#--------------------------------------------------------------------------------

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar r $@ $(OBJS)

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o

depall :
	gccmakedep	$(SRCS) $(INCLUDES) $(DEFS)

dep :
	gccmakedep	$(SRCS) $(INCLUDES) $(DEFS)


# DO NOT DELETE
LCCreatePCError.o: LCCreatePCError.cpp LCCreatePCError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCCreatePCErrorHandler.o: LCCreatePCErrorHandler.cpp LCCreatePCError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCCreatePCOK.o: LCCreatePCOK.cpp LCCreatePCOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCCreatePCOKHandler.o: LCCreatePCOKHandler.cpp LCCreatePCOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCDeletePCError.o: LCDeletePCError.cpp LCDeletePCError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCDeletePCErrorHandler.o: LCDeletePCErrorHandler.cpp LCDeletePCError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCDeletePCOK.o: LCDeletePCOK.cpp LCDeletePCOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCDeletePCOKHandler.o: LCDeletePCOKHandler.cpp LCDeletePCOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCLoginError.o: LCLoginError.cpp LCLoginError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCLoginErrorHandler.o: LCLoginErrorHandler.cpp LCLoginError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCLoginOK.o: LCLoginOK.cpp LCLoginOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCLoginOKHandler.o: LCLoginOKHandler.cpp LCLoginOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCPCList.o: LCPCList.cpp LCPCList.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/PCInfo.h \
  $(SRCDIR)/Core/PCSlayerInfo.h \
  $(SRCDIR)/Core/PCInfo.h \
  /usr/include/STL/bitset /usr/include/STL/stl/_bitset.h \
  /usr/include/STL/stl/_bitset.c \
  $(SRCDIR)/Core/PCVampireInfo.h \
  $(SRCDIR)/Core/PCOustersInfo.h
LCPCListHandler.o: LCPCListHandler.cpp LCPCList.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/PCInfo.h \
  $(SRCDIR)/Core/PCSlayerInfo.h \
  $(SRCDIR)/Core/PCInfo.h \
  /usr/include/STL/bitset /usr/include/STL/stl/_bitset.h \
  /usr/include/STL/stl/_bitset.c \
  $(SRCDIR)/Core/PCVampireInfo.h \
  $(SRCDIR)/Core/PCOustersInfo.h
LCQueryResultPlayerID.o: LCQueryResultPlayerID.cpp \
  LCQueryResultPlayerID.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCQueryResultPlayerIDHandler.o: LCQueryResultPlayerIDHandler.cpp \
  LCQueryResultPlayerID.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCQueryResultCharacterName.o: LCQueryResultCharacterName.cpp \
  LCQueryResultCharacterName.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCQueryResultCharacterNameHandler.o:  \
 LCQueryResultCharacterNameHandler.cpp LCQueryResultCharacterName.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCReconnect.o: LCReconnect.cpp LCReconnect.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCReconnectHandler.o: LCReconnectHandler.cpp LCReconnect.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCRegisterPlayerError.o: LCRegisterPlayerError.cpp \
  LCRegisterPlayerError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCRegisterPlayerErrorHandler.o: LCRegisterPlayerErrorHandler.cpp \
  LCRegisterPlayerError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCRegisterPlayerOK.o: LCRegisterPlayerOK.cpp LCRegisterPlayerOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCRegisterPlayerOKHandler.o: LCRegisterPlayerOKHandler.cpp \
  LCRegisterPlayerOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCSelectPCError.o: LCSelectPCError.cpp LCSelectPCError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCSelectPCErrorHandler.o: LCSelectPCErrorHandler.cpp LCSelectPCError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCServerList.o: LCServerList.cpp LCServerList.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/ServerGroupInfo.h \
  $(SRCDIR)/Core/PCSlayerInfo.h \
  $(SRCDIR)/Core/PCInfo.h \
  /usr/include/STL/bitset /usr/include/STL/stl/_bitset.h \
  /usr/include/STL/stl/_bitset.c \
  $(SRCDIR)/Core/PCVampireInfo.h
LCServerListHandler.o: LCServerListHandler.cpp LCServerList.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/ServerGroupInfo.h
LCWorldList.o: LCWorldList.cpp LCWorldList.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/WorldInfo.h \
  $(SRCDIR)/Core/PCSlayerInfo.h \
  $(SRCDIR)/Core/PCInfo.h \
  /usr/include/STL/bitset /usr/include/STL/stl/_bitset.h \
  /usr/include/STL/stl/_bitset.c \
  $(SRCDIR)/Core/PCVampireInfo.h
LCWorldListHandler.o: LCWorldListHandler.cpp LCWorldList.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/WorldInfo.h
LCVersionCheckOK.o: LCVersionCheckOK.cpp LCVersionCheckOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCVersionCheckOKHandler.o: LCVersionCheckOKHandler.cpp LCVersionCheckOK.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCVersionCheckError.o: LCVersionCheckError.cpp LCVersionCheckError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCVersionCheckErrorHandler.o: LCVersionCheckErrorHandler.cpp \
  LCVersionCheckError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LGIncomingConnection.o: LGIncomingConnection.cpp LGIncomingConnection.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/Datagram.h \
  /usr/include/arpa/inet.h \
  $(SRCDIR)/Core/PacketFactory.h
LGIncomingConnectionHandler.o: LGIncomingConnectionHandler.cpp \
  LGIncomingConnection.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/Datagram.h \
  /usr/include/arpa/inet.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Properties.h \
  /usr/include/STL/map /usr/include/STL/stl/_map.h \
  /usr/include/STL/stl/_tree.h /usr/include/STL/stl/_tree.c \
  $(SRCDIR)/server/gameserver/ConnectionInfo.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/Timeval.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  $(SRCDIR)/server/gameserver/ConnectionInfoManager.h \
  $(SRCDIR)/server/Mutex.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  /usr/include/STL/hash_map /usr/include/STL/stl/_hash_map.h \
  /usr/include/STL/stl/_hashtable.h /usr/include/STL/stl/_vector.h \
  /usr/include/STL/stl/_vector.c /usr/include/STL/stl/_bvector.h \
  /usr/include/STL/stl/_slist.h /usr/include/STL/stl/_slist_base.h \
  /usr/include/STL/stl/_slist_base.c /usr/include/STL/stl/_slist.c \
  /usr/include/STL/stl/_hashtable.c \
  /usr/include/STL/stl/_relops_hash_cont.h \
  $(SRCDIR)/server/gameserver/ConnectionInfo.h \
  $(SRCDIR)/server/gameserver/LoginServerManager.h \
  $(SRCDIR)/server/Thread.h \
  $(SRCDIR)/server/pthreadAPI.h \
  $(SRCDIR)/Core/DatagramSocket.h \
  $(SRCDIR)/server/gameserver/LogDef.h \
  $(SRCDIR)/server/gameserver/VariableManager.h \
  /usr/include/STL/vector \
  $(SRCDIR)/Core/Gpackets/GLIncomingConnectionError.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Gpackets/GLIncomingConnectionOK.h
LGIncomingConnectionOK.o: LGIncomingConnectionOK.cpp \
  LGIncomingConnectionOK.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/Datagram.h \
  /usr/include/arpa/inet.h \
  $(SRCDIR)/Core/PacketFactory.h
LGIncomingConnectionOKHandler.o: LGIncomingConnectionOKHandler.cpp \
  LGIncomingConnectionOK.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/Datagram.h \
  /usr/include/arpa/inet.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/server/gameserver/GamePlayer.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/Player.h \
  $(SRCDIR)/Core/SocketEncryptOutputStream.h \
  $(SRCDIR)/Core/Encrypter.h \
  $(SRCDIR)/Core/EncryptUtility.h \
  $(SRCDIR)/Core/SocketEncryptInputStream.h \
  $(SRCDIR)/server/Mutex.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  /usr/include/STL/deque /usr/include/STL/stl/_deque.h \
  /usr/include/STL/stl/_deque.c \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/server/Timeval.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  $(SRCDIR)/Core/PlayerStatus.h \
  $(SRCDIR)/server/gameserver/EventManager.h \
  $(SRCDIR)/server/gameserver/Event.h \
  $(SRCDIR)/server/gameserver/skill/Skill.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/server/PaySystem.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/Core/VSDateTime.h \
  $(SRCDIR)/server/gameserver/Item.h \
  $(SRCDIR)/server/gameserver/Object.h \
  $(SRCDIR)/Core/Assert.h \
  $(SRCDIR)/server/gameserver/Effect.h \
  $(SRCDIR)/server/gameserver/EffectManager.h \
  $(SRCDIR)/Core/EffectInfo.h \
  /usr/include/STL/bitset /usr/include/STL/stl/_bitset.h \
  /usr/include/STL/stl/_bitset.c /usr/include/STL/vector \
  /usr/include/STL/stl/_vector.h /usr/include/STL/stl/_vector.c \
  /usr/include/STL/stl/_bvector.h /usr/include/STL/algorithm \
  /usr/include/STL/stl/_cstdio.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdio \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/gconv.h \
  /usr/include/bits/sys_errlist.h /usr/include/STL/stl/_algo.h \
  /usr/include/STL/stl/_heap.h /usr/include/STL/stl/_heap.c \
  /usr/include/STL/stl/_algo.c /usr/include/STL/stl/_tempbuf.h \
  /usr/include/STL/stl/_tempbuf.c \
  $(SRCDIR)/server/gameserver/billing/BillingPlayerInfo.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/server/chinabilling/CBillingPlayerInfo.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/server/chinabilling/CBillingInfo.h \
  $(SRCDIR)/Core/VSDateTime.h \
  $(SRCDIR)/Core/Gpackets/GCReconnectLogin.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/PacketFactory.h \
  /usr/include/STL/hash_map /usr/include/STL/stl/_hash_map.h \
  /usr/include/STL/stl/_hashtable.h /usr/include/STL/stl/_slist.h \
  /usr/include/STL/stl/_slist_base.h /usr/include/STL/stl/_slist_base.c \
  /usr/include/STL/stl/_slist.c /usr/include/STL/stl/_hashtable.c \
  /usr/include/STL/stl/_relops_hash_cont.h \
  $(SRCDIR)/server/gameserver/gameguard/CSAuth.h \
  $(SRCDIR)/server/gameserver/IncomingPlayerManager.h \
  $(SRCDIR)/server/PlayerManager.h \
  $(SRCDIR)/Core/SocketAPI.h \
  $(SRCDIR)/server/Mutex.h \
  $(SRCDIR)/server/gameserver/GamePlayer.h \
  $(SRCDIR)/Core/ServerSocket.h \
  $(SRCDIR)/Core/DatagramSocket.h \
  $(SRCDIR)/server/gameserver/ConnectionInfoManager.h \
  $(SRCDIR)/server/gameserver/ConnectionInfo.h \
  $(SRCDIR)/Core/Assert.h \
  $(SRCDIR)/server/database/Statement.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/database/Connection.h \
  /usr/include/mysql/mysql.h /usr/include/mysql/mysql_com.h \
  /usr/include/mysql/mysql_version.h \
  $(SRCDIR)/server/Mutex.h \
  $(SRCDIR)/server/database/DatabaseManager.h \
  $(SRCDIR)/server/gameserver/LogDef.h \
  $(SRCDIR)/server/gameserver/VariableManager.h \
  $(SRCDIR)/Core/Gpackets/GCReconnectLogin.h
LGIncomingConnectionError.o: LGIncomingConnectionError.cpp \
  LGIncomingConnectionError.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/Datagram.h \
  /usr/include/arpa/inet.h \
  $(SRCDIR)/Core/PacketFactory.h
LGIncomingConnectionErrorHandler.o: LGIncomingConnectionErrorHandler.cpp \
  LGIncomingConnectionError.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/Datagram.h \
  /usr/include/arpa/inet.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/server/gameserver/GamePlayer.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/Player.h \
  $(SRCDIR)/Core/SocketEncryptOutputStream.h \
  $(SRCDIR)/Core/Encrypter.h \
  $(SRCDIR)/Core/EncryptUtility.h \
  $(SRCDIR)/Core/SocketEncryptInputStream.h \
  $(SRCDIR)/server/Mutex.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  /usr/include/STL/deque /usr/include/STL/stl/_deque.h \
  /usr/include/STL/stl/_deque.c \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/server/Timeval.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  $(SRCDIR)/Core/PlayerStatus.h \
  $(SRCDIR)/server/gameserver/EventManager.h \
  $(SRCDIR)/server/gameserver/Event.h \
  $(SRCDIR)/server/gameserver/skill/Skill.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/server/PaySystem.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/Core/VSDateTime.h \
  $(SRCDIR)/server/gameserver/Item.h \
  $(SRCDIR)/server/gameserver/Object.h \
  $(SRCDIR)/Core/Assert.h \
  $(SRCDIR)/server/gameserver/Effect.h \
  $(SRCDIR)/server/gameserver/EffectManager.h \
  $(SRCDIR)/Core/EffectInfo.h \
  /usr/include/STL/bitset /usr/include/STL/stl/_bitset.h \
  /usr/include/STL/stl/_bitset.c /usr/include/STL/vector \
  /usr/include/STL/stl/_vector.h /usr/include/STL/stl/_vector.c \
  /usr/include/STL/stl/_bvector.h /usr/include/STL/algorithm \
  /usr/include/STL/stl/_cstdio.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdio \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/gconv.h \
  /usr/include/bits/sys_errlist.h /usr/include/STL/stl/_algo.h \
  /usr/include/STL/stl/_heap.h /usr/include/STL/stl/_heap.c \
  /usr/include/STL/stl/_algo.c /usr/include/STL/stl/_tempbuf.h \
  /usr/include/STL/stl/_tempbuf.c \
  $(SRCDIR)/server/gameserver/billing/BillingPlayerInfo.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/server/chinabilling/CBillingPlayerInfo.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/server/chinabilling/CBillingInfo.h \
  $(SRCDIR)/Core/VSDateTime.h \
  $(SRCDIR)/Core/Gpackets/GCReconnectLogin.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/PacketFactory.h \
  /usr/include/STL/hash_map /usr/include/STL/stl/_hash_map.h \
  /usr/include/STL/stl/_hashtable.h /usr/include/STL/stl/_slist.h \
  /usr/include/STL/stl/_slist_base.h /usr/include/STL/stl/_slist_base.c \
  /usr/include/STL/stl/_slist.c /usr/include/STL/stl/_hashtable.c \
  /usr/include/STL/stl/_relops_hash_cont.h \
  $(SRCDIR)/server/gameserver/gameguard/CSAuth.h \
  $(SRCDIR)/server/gameserver/IncomingPlayerManager.h \
  $(SRCDIR)/server/PlayerManager.h \
  $(SRCDIR)/Core/SocketAPI.h \
  $(SRCDIR)/server/Mutex.h \
  $(SRCDIR)/server/gameserver/GamePlayer.h \
  $(SRCDIR)/Core/ServerSocket.h \
  $(SRCDIR)/Core/DatagramSocket.h \
  $(SRCDIR)/server/gameserver/ConnectionInfoManager.h \
  $(SRCDIR)/server/gameserver/ConnectionInfo.h \
  $(SRCDIR)/Core/Assert.h \
  $(SRCDIR)/server/gameserver/LogDef.h \
  $(SRCDIR)/server/gameserver/VariableManager.h
LGKickCharacter.o: LGKickCharacter.cpp LGKickCharacter.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/Datagram.h \
  /usr/include/arpa/inet.h \
  $(SRCDIR)/Core/PacketFactory.h
LGKickCharacterHandler.o: LGKickCharacterHandler.cpp LGKickCharacter.h \
  $(SRCDIR)/Core/DatagramPacket.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/Datagram.h \
  /usr/include/arpa/inet.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/server/gameserver/GamePlayer.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/Player.h \
  $(SRCDIR)/Core/SocketEncryptOutputStream.h \
  $(SRCDIR)/Core/Encrypter.h \
  $(SRCDIR)/Core/EncryptUtility.h \
  $(SRCDIR)/Core/SocketEncryptInputStream.h \
  $(SRCDIR)/server/Mutex.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  /usr/include/STL/deque /usr/include/STL/stl/_deque.h \
  /usr/include/STL/stl/_deque.c \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/server/Timeval.h \
  /usr/include/unistd.h /usr/include/bits/posix_opt.h \
  /usr/include/bits/environments.h /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  $(SRCDIR)/Core/PlayerStatus.h \
  $(SRCDIR)/server/gameserver/EventManager.h \
  $(SRCDIR)/server/gameserver/Event.h \
  $(SRCDIR)/server/gameserver/skill/Skill.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/server/PaySystem.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/Core/VSDateTime.h \
  $(SRCDIR)/server/gameserver/Item.h \
  $(SRCDIR)/server/gameserver/Object.h \
  $(SRCDIR)/Core/Assert.h \
  $(SRCDIR)/server/gameserver/Effect.h \
  $(SRCDIR)/server/gameserver/EffectManager.h \
  $(SRCDIR)/Core/EffectInfo.h \
  /usr/include/STL/bitset /usr/include/STL/stl/_bitset.h \
  /usr/include/STL/stl/_bitset.c /usr/include/STL/vector \
  /usr/include/STL/stl/_vector.h /usr/include/STL/stl/_vector.c \
  /usr/include/STL/stl/_bvector.h /usr/include/STL/algorithm \
  /usr/include/STL/stl/_cstdio.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdio \
  /usr/include/libio.h /usr/include/_G_config.h /usr/include/gconv.h \
  /usr/include/bits/sys_errlist.h /usr/include/STL/stl/_algo.h \
  /usr/include/STL/stl/_heap.h /usr/include/STL/stl/_heap.c \
  /usr/include/STL/stl/_algo.c /usr/include/STL/stl/_tempbuf.h \
  /usr/include/STL/stl/_tempbuf.c \
  $(SRCDIR)/server/gameserver/billing/BillingPlayerInfo.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/server/chinabilling/CBillingPlayerInfo.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/server/chinabilling/CBillingInfo.h \
  $(SRCDIR)/Core/VSDateTime.h \
  $(SRCDIR)/Core/Gpackets/GCReconnectLogin.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/PacketFactory.h \
  /usr/include/STL/hash_map /usr/include/STL/stl/_hash_map.h \
  /usr/include/STL/stl/_hashtable.h /usr/include/STL/stl/_slist.h \
  /usr/include/STL/stl/_slist_base.h /usr/include/STL/stl/_slist_base.c \
  /usr/include/STL/stl/_slist.c /usr/include/STL/stl/_hashtable.c \
  /usr/include/STL/stl/_relops_hash_cont.h \
  $(SRCDIR)/server/gameserver/gameguard/CSAuth.h \
  $(SRCDIR)/server/gameserver/LoginServerManager.h \
  $(SRCDIR)/server/Thread.h \
  $(SRCDIR)/server/pthreadAPI.h \
  $(SRCDIR)/Core/DatagramSocket.h \
  $(SRCDIR)/server/gameserver/Creature.h \
  $(SRCDIR)/server/gameserver/PCFinder.h \
  $(SRCDIR)/server/gameserver/Creature.h \
  $(SRCDIR)/server/gameserver/NPC.h \
  $(SRCDIR)/server/gameserver/Zone.h \
  $(SRCDIR)/server/gameserver/Tile.h \
  /usr/include/STL/slist \
  $(SRCDIR)/server/gameserver/Obstacle.h \
  $(SRCDIR)/server/gameserver/Portal.h \
  $(SRCDIR)/server/gameserver/quest/TriggerManager.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/server/gameserver/quest/Trigger.h \
  $(SRCDIR)/server/gameserver/quest/Condition.h \
  $(SRCDIR)/server/gameserver/quest/PropertyBuffer.h \
  $(SRCDIR)/server/gameserver/Sector.h \
  $(SRCDIR)/server/gameserver/ObjectRegistry.h \
  $(SRCDIR)/server/gameserver/Party.h \
  $(SRCDIR)/Core/ModifyInfo.h \
  $(SRCDIR)/server/gameserver/PCManager.h \
  $(SRCDIR)/server/gameserver/CreatureManager.h \
  $(SRCDIR)/Core/Encrypter.h \
  /usr/include/STL/queue /usr/include/STL/stl/_queue.h \
  /usr/include/STL/functional /usr/include/STL/stl/_function.h \
  /usr/include/STL/stl/_function_adaptors.h \
  $(SRCDIR)/server/gameserver/Inventory.h \
  $(SRCDIR)/server/gameserver/VolumeInfo.h \
  $(SRCDIR)/server/gameserver/InventorySlot.h \
  $(SRCDIR)/server/gameserver/couple/PartnerWaitingManager.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/server/Timeval.h \
  $(SRCDIR)/server/gameserver/PlayerCreature.h \
  $(SRCDIR)/server/gameserver/Garbage.h \
  $(SRCDIR)/server/gameserver/RankBonus.h \
  $(SRCDIR)/server/gameserver/ExpFwd.h \
  $(SRCDIR)/Core/Gpackets/GCMonsterKillQuestInfo.h \
  $(SRCDIR)/Core/Gpackets/GCSelectQuestID.h \
  $(SRCDIR)/server/gameserver/OptionInfo.h \
  $(SRCDIR)/Core/VSDateTime.h \
  $(SRCDIR)/Core/GearInfo.h \
  $(SRCDIR)/Core/GearSlotInfo.h \
  $(SRCDIR)/Core/PCItemInfo.h \
  $(SRCDIR)/Core/SubItemInfo.h \
  $(SRCDIR)/Core/Assert.h \
  /usr/include/STL/map /usr/include/STL/stl/_map.h \
  /usr/include/STL/stl/_tree.h /usr/include/STL/stl/_tree.c \
  $(SRCDIR)/server/gameserver/LogDef.h \
  $(SRCDIR)/server/gameserver/VariableManager.h \
  $(SRCDIR)/Core/Gpackets/GLKickVerify.h \
  $(SRCDIR)/Core/DatagramPacket.h
LCShowWebPage.o: LCShowWebPage.cpp LCShowWebPage.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCShowWebPageHandler.o: LCShowWebPageHandler.cpp LCShowWebPage.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCSelectWorldError.o: LCSelectWorldError.cpp LCSelectWorldError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
LCSelectWorldErrorHandler.o: LCSelectWorldErrorHandler.cpp \
  LCSelectWorldError.h \
  $(SRCDIR)/Core/Packet.h \
  $(SRCDIR)/Core/Types.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  /usr/include/sys/types.h /usr/include/features.h \
  /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h /usr/include/STL/stddef.h \
  /usr/include/STL/stl/_prolog.h /usr/include/STL/stl/config/features.h \
  /usr/include/STL/stl/_stlport_version.h \
  /usr/include/STL/stl/config/user_config.h \
  /usr/include/STL/stl/config/compat.h /usr/include/STL/stl/config/host.h \
  /usr/include/STL/stl/config/_system.h \
  /usr/include/STL/stl/config/_linux.h /usr/include/endian.h \
  /usr/include/bits/endian.h /usr/include/STL/stl/config/_gcc.h \
  /usr/include/STL/stl/config/stl_confix.h \
  /usr/include/STL/stl/config/_native_headers.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stddef.h \
  /usr/include/STL/stl/_epilog.h \
  /usr/include/STL/stl/_config_compat_post.h \
  /usr/include/bits/typesizes.h /usr/include/STL/time.h \
  /usr/include/../include/time.h /usr/include/sys/select.h \
  /usr/include/bits/select.h /usr/include/bits/sigset.h \
  /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h /usr/include/STL/iostream \
  /usr/include/STL/stl/_ioserr.h /usr/include/STL/stl/_iosfwd.h \
  /usr/include/STL/stl/char_traits.h /usr/include/STL/stl/_cstddef.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstddef \
  /usr/include/STL/stl/_cstring.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstring \
  /usr/include/STL/cstddef /usr/include/STL/string.h \
  /usr/include/../include/string.h /usr/include/xlocale.h \
  /usr/include/STL/using/cstring /usr/include/STL/stl/_construct.h \
  /usr/include/STL/stl/_new.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/new \
  /usr/include/STL/exception \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/exception \
  /usr/include/STL/stl/_iterator_base.h \
  /usr/include/STL/stl/_move_construct_fwk.h \
  /usr/include/STL/stl/type_traits.h /usr/include/STL/stl/type_manips.h \
  /usr/include/STL/stl/_cwchar.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cwchar \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/c++config.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/os_defines.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/i386-redhat-linux/bits/cpu_defines.h \
  /usr/include/STL/ctime \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/ctime \
  /usr/include/STL/wchar.h /usr/include/../include/wchar.h \
  /usr/include/STL/stdio.h /usr/include/../include/stdio.h \
  /usr/include/STL/stdarg.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/stdarg.h \
  /usr/include/bits/wchar.h /usr/include/STL/stl/_mbstate_t.h \
  /usr/include/STL/stl/_istream.h /usr/include/STL/stl/_ios.h \
  /usr/include/STL/stl/_ios_base.h /usr/include/STL/stl/_stdexcept_base.h \
  /usr/include/STL/stl/_exception.h /usr/include/STL/stl/_string_fwd.h \
  /usr/include/STL/iosfwd /usr/include/STL/utility \
  /usr/include/STL/stl/_pair.h /usr/include/STL/stl/_locale.h \
  /usr/include/STL/stl/_cstdlib.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cstdlib \
  /usr/include/STL/stdlib.h /usr/include/../include/stdlib.h \
  /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
  /usr/include/alloca.h /usr/include/STL/stl/_cmath.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cmath \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cpp_type_traits.h \
  /usr/include/STL/math.h /usr/include/../include/math.h \
  /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h \
  /usr/include/bits/huge_vall.h /usr/include/bits/inf.h \
  /usr/include/bits/nan.h /usr/include/bits/mathdef.h \
  /usr/include/bits/mathcalls.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/bits/cmath.tcc \
  /usr/include/STL/stl/_threads.h /usr/include/STL/pthread.h \
  /usr/include/../include/pthread.h /usr/include/sched.h \
  /usr/include/bits/sched.h /usr/include/STL/signal.h \
  /usr/include/../include/signal.h /usr/include/bits/setjmp.h \
  /usr/include/STL/stl/_threads.c /usr/include/STL/stl/_ctime.h \
  /usr/include/sys/time.h /usr/include/STL/stl/_string.h \
  /usr/include/STL/stl/_alloc.h /usr/include/STL/stl/_algobase.h \
  /usr/include/STL/climits \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/climits \
  /usr/include/STL/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/limits.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/syslimits.h \
  /usr/include/limits.h /usr/include/bits/posix1_lim.h \
  /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
  /usr/include/bits/posix2_lim.h /usr/include/bits/xopen_lim.h \
  /usr/include/bits/stdio_lim.h /usr/include/STL/stl/_algobase.c \
  /usr/include/STL/stl/_iterator.h /usr/include/STL/stl/_alloc.c \
  /usr/include/STL/stl/_function_base.h \
  /usr/include/STL/stl/_uninitialized.h \
  /usr/include/STL/stl/_string_base.h /usr/include/STL/stl/_string_npos.h \
  /usr/include/STL/stl/_string_operators.h /usr/include/STL/stl/_string.c \
  /usr/include/STL/stl/_ctraits_fns.h \
  /usr/include/STL/stl/_range_errors.h /usr/include/STL/stl/_ctype.h \
  /usr/include/STL/stl/c_locale.h /usr/include/STL/ctype.h \
  /usr/include/../include/ctype.h /usr/include/STL/stl/_numpunct.h \
  /usr/include/STL/stl/_ios.c /usr/include/STL/stl/_streambuf.h \
  /usr/include/STL/stl/_streambuf.c /usr/include/STL/stl/_ostream.h \
  /usr/include/STL/stl/_ostreambuf_iterator.h \
  /usr/include/STL/stl/_ostream.c /usr/include/STL/stl/_num_put.h \
  /usr/include/STL/stl/_iostream_string.h /usr/include/STL/stl/_num_put.c \
  /usr/include/STL/stl/_limits.h /usr/include/STL/cfloat \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/../../../../include/c++/4.1.1/../4.1.1/cfloat \
  /usr/include/STL/float.h \
  /usr/lib/gcc/i386-redhat-linux/4.1.1/include/../include/float.h \
  /usr/include/STL/stl/_limits.c \
  /usr/include/STL/stl/_istreambuf_iterator.h \
  /usr/include/STL/stl/_istream.c /usr/include/STL/stl/_num_get.h \
  /usr/include/STL/stl/_num_get.c /usr/include/STL/fstream \
  /usr/include/STL/stl/_fstream.h /usr/include/STL/stl/_codecvt.h \
  /usr/include/STL/stl/_fstream.c /usr/include/STL/string \
  /usr/include/STL/stl/_string_hash.h /usr/include/STL/stl/_hash_fun.h \
  /usr/include/STL/stl/_string_io.h /usr/include/STL/stl/_string_io.c \
  $(SRCDIR)/Core/types/PlayerTypes.h \
  $(SRCDIR)/Core/types/SystemTypes.h \
  $(SRCDIR)/Core/types/ObjectTypes.h \
  $(SRCDIR)/Core/types/CreatureTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/ZoneTypes.h \
  $(SRCDIR)/Core/types/QuestTypes.h \
  $(SRCDIR)/Core/types/ShopTypes.h \
  $(SRCDIR)/Core/types/ItemTypes.h \
  $(SRCDIR)/Core/types/GuildTypes.h \
  $(SRCDIR)/Core/types/WarTypes.h \
  $(SRCDIR)/Core/types/ServerType.h \
  $(SRCDIR)/Core/types/VersionType.h \
  $(SRCDIR)/Core/Utility.h \
  $(SRCDIR)/Core/Exception.h \
  $(SRCDIR)/Core/StringStream.h \
  /usr/include/STL/list /usr/include/STL/stl/_list.h \
  /usr/include/STL/stl/_list.c /usr/include/STL/stl/_carray.h \
  /usr/include/STL/stl/_relops_cont.h \
  $(SRCDIR)/Core/SocketInputStream.h \
  $(SRCDIR)/Core/Socket.h \
  $(SRCDIR)/Core/SocketImpl.h \
  $(SRCDIR)/Core/SocketAPI.h \
  /usr/include/netinet/in.h /usr/include/stdint.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/bits/uio.h /usr/include/bits/socket.h \
  /usr/include/bits/sockaddr.h /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h /usr/include/bits/in.h \
  /usr/include/bits/byteswap.h \
  $(SRCDIR)/Core/SocketOutputStream.h \
  $(SRCDIR)/Core/PacketFactory.h \
  $(SRCDIR)/Core/Packet.h
