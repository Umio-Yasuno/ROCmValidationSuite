/********************************************************************************
 *
 * Copyright (c) 2018 ROCm Developer Tools
 *
 * MIT LICENSE:
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *******************************************************************************/
#ifndef RVSLIBLOG_H_
#define RVSLIBLOG_H_


#ifdef __cplusplus
extern "C" {
#endif

typedef int   (*t_rvs_module_log)(const char*, const int);
typedef int   (*t_cbLogExt)(const char*, const int, const unsigned int Sec, const unsigned int uSec);
typedef void* (*t_cbLogRecordCreate)( const char* Module, const char* Action, const int LogLevel, const unsigned int Sec, const unsigned int uSec);
typedef int   (*t_cbLogRecordFlush)( void* pLogRecord);
typedef void* (*t_cbCreateNode)(void* Parent, const char* Name);
typedef void  (*t_cbAddString)(void* Parent, const char* Key, const char* Val);
typedef void  (*t_cbAddInt)(void* Parent, const char* Key, const int Val);
typedef void  (*t_cbAddNode)(void* Parent, void* Child);

typedef struct tag_module_init 
{
  t_rvs_module_log     cbLog;
  t_cbLogExt           cbLogExt;
  t_cbLogRecordCreate  cbLogRecordCreate;
  t_cbLogRecordFlush   cbLogRecordFlush;
  t_cbCreateNode       cbCreateNode;
  t_cbAddString        cbAddString;
  t_cbAddInt           cbAddInt;
  t_cbAddNode          cbAddNode;

} T_MODULE_INIT;

#ifdef __cplusplus
}
#endif


namespace rvs
{

const int lognone     = 0;
const int logresults  = 1;
const int logerror    = 2;
const int loginfo    = 3;
const int logdebug    = 4;
const int logtrace    = 5;

}  // namespace rvs






#endif // RVSLIBLOG_H_