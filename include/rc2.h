/*************************************************
* RC2 Header File                                *
* (C) 1999-2007 The Botan Project                *
*************************************************/

#ifndef BOTAN_RC2_H__
#define BOTAN_RC2_H__

#include <botan/base.h>

namespace Botan {

/*************************************************
* RC2                                            *
*************************************************/
class RC2 : public BlockCipher
   {
   public:
      static byte EKB_code(u32bit);

      void clear() throw() { K.clear(); }
      std::string name() const { return "RC2"; }
      BlockCipher* clone() const { return new RC2; }
      RC2() : BlockCipher(8, 1, 32) {}
   private:
      void enc(const byte[], byte[]) const;
      void dec(const byte[], byte[]) const;
      void key(const byte[], u32bit);

      SecureBuffer<u16bit, 64> K;
   };

}

#endif
