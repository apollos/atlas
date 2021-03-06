/*
 *             Automatically Tuned Linear Algebra Software v3.10.2
 * Copyright (C) 2010 R. Clint Whaley
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions, and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *   3. The name of the ATLAS group or the names of its contributers may
 *      not be used to endorse or promote products derived from this
 *      software without specific written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE ATLAS GROUP OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include "atlas_misc.h"

void Mjoin(PATL,trsetL)
   (ATL_CINT M, ATL_CINT N, const SCALAR alpha, const SCALAR beta,
    TYPE *A, ATL_CINT lda)
/*
 * Sets main diagonal to beta, rest of lower triangle to alpha, does not
 * touch upper triangle
 */
{

   ATL_INT j;
   #ifdef TCPLX
      ATL_CINT ldap1 = lda+1;
   #else
      ATL_CINT ldap1 = lda+lda+2;
   #endif

   for (j=0; j < N; j++, A += ldap1)
   {
      #ifdef TCPLX
         *A = *beta;
         A[1] = beta[1];
      #else
         *A = beta;
      #endif
      if (N-j-1)
         Mjoin(PATL,set)(N-j-1, alpha, A+(1 SHIFT), 1);
   }
}
