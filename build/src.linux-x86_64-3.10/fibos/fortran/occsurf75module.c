/* File: occsurf75module.c
 * This file is auto-generated with f2py (version:1.25.1).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Fri Aug 11 00:44:52 2023
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif /* PY_SSIZE_T_CLEAN */

/* Unconditionally included */
#include <Python.h>
#include <numpy/npy_os.h>

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "fortranobject.h"
#include <string.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *occsurf75_error;
static PyObject *occsurf75_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
typedef char * string;

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
\
#define FAILNULL(p) do {                                            \
    if ((p) == NULL) {                                              \
        PyErr_SetString(PyExc_MemoryError, "NULL pointer found");   \
        goto capi_fail;                                             \
    }                                                               \
} while (0)

#define STRINGMALLOC(str,len)\
    if ((str = (string)malloc(len+1)) == NULL) {\
        PyErr_SetString(PyExc_MemoryError, "out of memory");\
        goto capi_fail;\
    } else {\
        (str)[len] = '\0';\
    }

#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif

/* See fortranobject.h for definitions. The macros here are provided for BC. */
#define rank f2py_rank
#define shape f2py_shape
#define fshape f2py_shape
#define len f2py_len
#define flen f2py_flen
#define slen f2py_slen
#define size f2py_size

#define STRINGFREE(str) do {if (!(str == NULL)) free(str);} while (0)

/*
STRINGPADN replaces null values with padding values from the right.

`to` must have size of at least N bytes.

If the `to[N-1]` has null value, then replace it and all the
preceding, nulls with the given padding.

STRINGPADN(to, N, PADDING, NULLVALUE) is an inverse operation.
*/
#define STRINGPADN(to, N, NULLVALUE, PADDING)                   \
    do {                                                        \
        int _m = (N);                                           \
        char *_to = (to);                                       \
        for (_m -= 1; _m >= 0 && _to[_m] == NULLVALUE; _m--) {  \
             _to[_m] = PADDING;                                 \
        }                                                       \
    } while (0)

/*
STRINGCOPYN copies N bytes.

`to` and `from` buffers must have sizes of at least N bytes.
*/
#define STRINGCOPYN(to,from,N)                                  \
    do {                                                        \
        int _m = (N);                                           \
        char *_to = (to);                                       \
        char *_from = (from);                                   \
        FAILNULL(_to); FAILNULL(_from);                         \
        (void)strncpy(_to, _from, _m);             \
    } while (0)


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int
double_from_pyobj(double* v, PyObject *obj, const char *errmess)
{
    PyObject* tmp = NULL;
    if (PyFloat_Check(obj)) {
        *v = PyFloat_AsDouble(obj);
        return !(*v == -1.0 && PyErr_Occurred());
    }

    tmp = PyNumber_Float(obj);
    if (tmp) {
        *v = PyFloat_AsDouble(tmp);
        Py_DECREF(tmp);
        return !(*v == -1.0 && PyErr_Occurred());
    }

    if (PyComplex_Check(obj)) {
        PyErr_Clear();
        tmp = PyObject_GetAttrString(obj,"real");
    }
    else if (PyBytes_Check(obj) || PyUnicode_Check(obj)) {
        /*pass*/;
    }
    else if (PySequence_Check(obj)) {
        PyErr_Clear();
        tmp = PySequence_GetItem(obj, 0);
    }

    if (tmp) {
        if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = occsurf75_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}

/*
  Create a new string buffer `str` of at most length `len` from a
  Python string-like object `obj`.

  The string buffer has given size (len) or the size of inistr when len==-1.

  The string buffer is padded with blanks: in Fortran, trailing blanks
  are insignificant contrary to C nulls.
 */
static int
string_from_pyobj(string *str, int *len, const string inistr, PyObject *obj,
                  const char *errmess)
{
    PyObject *tmp = NULL;
    string buf = NULL;
    npy_intp n = -1;
#ifdef DEBUGCFUNCS
fprintf(stderr,"string_from_pyobj(str='%s',len=%d,inistr='%s',obj=%p)\n",
               (char*)str, *len, (char *)inistr, obj);
#endif
    if (obj == Py_None) {
        n = strlen(inistr);
        buf = inistr;
    }
    else if (PyArray_Check(obj)) {
        PyArrayObject *arr = (PyArrayObject *)obj;
        if (!ISCONTIGUOUS(arr)) {
            PyErr_SetString(PyExc_ValueError,
                            "array object is non-contiguous.");
            goto capi_fail;
        }
        n = PyArray_NBYTES(arr);
        buf = PyArray_DATA(arr);
        n = strnlen(buf, n);
    }
    else {
        if (PyBytes_Check(obj)) {
            tmp = obj;
            Py_INCREF(tmp);
        }
        else if (PyUnicode_Check(obj)) {
            tmp = PyUnicode_AsASCIIString(obj);
        }
        else {
            PyObject *tmp2;
            tmp2 = PyObject_Str(obj);
            if (tmp2) {
                tmp = PyUnicode_AsASCIIString(tmp2);
                Py_DECREF(tmp2);
            }
            else {
                tmp = NULL;
            }
        }
        if (tmp == NULL) goto capi_fail;
        n = PyBytes_GET_SIZE(tmp);
        buf = PyBytes_AS_STRING(tmp);
    }
    if (*len == -1) {
        /* TODO: change the type of `len` so that we can remove this */
        if (n > NPY_MAX_INT) {
            PyErr_SetString(PyExc_OverflowError,
                            "object too large for a 32-bit int");
            goto capi_fail;
        }
        *len = n;
    }
    else if (*len < n) {
        /* discard the last (len-n) bytes of input buf */
        n = *len;
    }
    if (n < 0 || *len < 0 || buf == NULL) {
        goto capi_fail;
    }
    STRINGMALLOC(*str, *len);  // *str is allocated with size (*len + 1)
    if (n < *len) {
        /*
          Pad fixed-width string with nulls. The caller will replace
          nulls with blanks when the corresponding argument is not
          intent(c).
        */
        memset(*str + n, '\0', *len - n);
    }
    STRINGCOPYN(*str, buf, n);
    Py_XDECREF(tmp);
    return 1;
capi_fail:
    Py_XDECREF(tmp);
    {
        PyObject* err = PyErr_Occurred();
        if (err == NULL) {
            err = occsurf75_error;
        }
        PyErr_SetString(err, errmess);
    }
    return 0;
}

static int
float_from_pyobj(float* v, PyObject *obj, const char *errmess)
{
    double d=0.0;
    if (double_from_pyobj(&d,obj,errmess)) {
        *v = (float)d;
        return 1;
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(occsurf,OCCSURF)(void);
extern void F_FUNC(aa1to3,AA1TO3)(string,string,size_t,size_t);
extern void F_FUNC(aadist,AADIST)(void);
extern void F_FUNC(getsfe,GETSFE)(string,float*,float*,float*,float*,size_t);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************** occsurf **********************************/
static char doc_f2py_rout_occsurf75_occsurf[] = "\
occsurf()\n\nWrapper for ``occsurf``.\
\n";
/* extern void F_FUNC(occsurf,OCCSURF)(void); */
static PyObject *f2py_rout_occsurf75_occsurf(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(void)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    static char *capi_kwlist[] = {NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "|:occsurf75.occsurf",\
        capi_kwlist))
        return NULL;
/*frompyobj*/
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)();
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of occsurf *******************************/

/*********************************** aa1to3 ***********************************/
static char doc_f2py_rout_occsurf75_aa1to3[] = "\
aa1to3(strng,onelc)\n\nWrapper for ``aa1to3``.\
\n\nParameters\n----------\n"
"strng : input string(len=3)\n"
"onelc : input string(len=1)";
/* extern void F_FUNC(aa1to3,AA1TO3)(string,string,size_t,size_t); */
static PyObject *f2py_rout_occsurf75_aa1to3(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(string,string,size_t,size_t)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    string strng = NULL;
    int slen(strng);
    PyObject *strng_capi = Py_None;
    string onelc = NULL;
    int slen(onelc);
    PyObject *onelc_capi = Py_None;
    static char *capi_kwlist[] = {"strng","onelc",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OO|:occsurf75.aa1to3",\
        capi_kwlist,&strng_capi,&onelc_capi))
        return NULL;
/*frompyobj*/
    /* Processing variable strng */
    slen(strng) = 3;
    f2py_success = string_from_pyobj(&strng,&slen(strng),"",strng_capi,"string_from_pyobj failed in converting 1st argument`strng' of occsurf75.aa1to3 to C string");
    if (f2py_success) {
        STRINGPADN(strng, slen(strng), '\0', ' ');
    /* Processing variable onelc */
    slen(onelc) = 1;
    f2py_success = string_from_pyobj(&onelc,&slen(onelc),"",onelc_capi,"string_from_pyobj failed in converting 2nd argument`onelc' of occsurf75.aa1to3 to C string");
    if (f2py_success) {
        STRINGPADN(onelc, slen(onelc), '\0', ' ');
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)(strng,onelc,slen(strng),slen(onelc));
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
        STRINGFREE(onelc);
    }  /*if (f2py_success) of onelc*/
    /* End of cleaning variable onelc */
        STRINGFREE(strng);
    }  /*if (f2py_success) of strng*/
    /* End of cleaning variable strng */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of aa1to3 *******************************/

/*********************************** aadist ***********************************/
static char doc_f2py_rout_occsurf75_aadist[] = "\
aadist()\n\nWrapper for ``aadist``.\
\n";
/* extern void F_FUNC(aadist,AADIST)(void); */
static PyObject *f2py_rout_occsurf75_aadist(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(void)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    static char *capi_kwlist[] = {NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "|:occsurf75.aadist",\
        capi_kwlist))
        return NULL;
/*frompyobj*/
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)();
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of aadist *******************************/

/*********************************** getsfe ***********************************/
static char doc_f2py_rout_occsurf75_getsfe[] = "\
getsfe(onelc,sfdeaa,sfdeaai,bstotal,estotal)\n\nWrapper for ``getsfe``.\
\n\nParameters\n----------\n"
"onelc : input string(len=1)\n"
"sfdeaa : input float\n"
"sfdeaai : input float\n"
"bstotal : input float\n"
"estotal : input float";
/* extern void F_FUNC(getsfe,GETSFE)(string,float*,float*,float*,float*,size_t); */
static PyObject *f2py_rout_occsurf75_getsfe(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(string,float*,float*,float*,float*,size_t)) {
    PyObject * volatile capi_buildvalue = NULL;
    volatile int f2py_success = 1;
/*decl*/

    string onelc = NULL;
    int slen(onelc);
    PyObject *onelc_capi = Py_None;
    float sfdeaa = 0;
    PyObject *sfdeaa_capi = Py_None;
    float sfdeaai = 0;
    PyObject *sfdeaai_capi = Py_None;
    float bstotal = 0;
    PyObject *bstotal_capi = Py_None;
    float estotal = 0;
    PyObject *estotal_capi = Py_None;
    static char *capi_kwlist[] = {"onelc","sfdeaa","sfdeaai","bstotal","estotal",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
    if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
        "OOOOO|:occsurf75.getsfe",\
        capi_kwlist,&onelc_capi,&sfdeaa_capi,&sfdeaai_capi,&bstotal_capi,&estotal_capi))
        return NULL;
/*frompyobj*/
    /* Processing variable onelc */
    slen(onelc) = 1;
    f2py_success = string_from_pyobj(&onelc,&slen(onelc),"",onelc_capi,"string_from_pyobj failed in converting 1st argument`onelc' of occsurf75.getsfe to C string");
    if (f2py_success) {
        STRINGPADN(onelc, slen(onelc), '\0', ' ');
    /* Processing variable sfdeaa */
        f2py_success = float_from_pyobj(&sfdeaa,sfdeaa_capi,"occsurf75.getsfe() 2nd argument (sfdeaa) can't be converted to float");
    if (f2py_success) {
    /* Processing variable sfdeaai */
        f2py_success = float_from_pyobj(&sfdeaai,sfdeaai_capi,"occsurf75.getsfe() 3rd argument (sfdeaai) can't be converted to float");
    if (f2py_success) {
    /* Processing variable bstotal */
        f2py_success = float_from_pyobj(&bstotal,bstotal_capi,"occsurf75.getsfe() 4th argument (bstotal) can't be converted to float");
    if (f2py_success) {
    /* Processing variable estotal */
        f2py_success = float_from_pyobj(&estotal,estotal_capi,"occsurf75.getsfe() 5th argument (estotal) can't be converted to float");
    if (f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
                (*f2py_func)(onelc,&sfdeaa,&sfdeaai,&bstotal,&estotal,slen(onelc));
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
        if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
        CFUNCSMESS("Building return value.\n");
        capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
        } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
    } /*if (f2py_success) of estotal*/
    /* End of cleaning variable estotal */
    } /*if (f2py_success) of bstotal*/
    /* End of cleaning variable bstotal */
    } /*if (f2py_success) of sfdeaai*/
    /* End of cleaning variable sfdeaai */
    } /*if (f2py_success) of sfdeaa*/
    /* End of cleaning variable sfdeaa */
        STRINGFREE(onelc);
    }  /*if (f2py_success) of onelc*/
    /* End of cleaning variable onelc */
/*end of cleanupfrompyobj*/
    if (capi_buildvalue == NULL) {
/*routdebugfailure*/
    } else {
/*routdebugleave*/
    }
    CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
    return capi_buildvalue;
}
/******************************* end of getsfe *******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

static FortranDataDef f2py_aaa_def[] = {
  {"sfeaa",2,{{20,10}},NPY_FLOAT, 1},
  {"aaname",2,{{20,3}},NPY_STRING, 1},
  {"a1c",2,{{20,1}},NPY_STRING, 1},
  {"sfe",1,{{20}},NPY_FLOAT, 1},
  {NULL}
};
static void f2py_setup_aaa(char *sfeaa,char *aaname,char *a1c,char *sfe) {
  int i_f2py=0;
  f2py_aaa_def[i_f2py++].data = sfeaa;
  f2py_aaa_def[i_f2py++].data = aaname;
  f2py_aaa_def[i_f2py++].data = a1c;
  f2py_aaa_def[i_f2py++].data = sfe;
}
extern void F_FUNC(f2pyinitaaa,F2PYINITAAA)(void(*)(char*,char*,char*,char*));
static void f2py_init_aaa(void) {
  F_FUNC(f2pyinitaaa,F2PYINITAAA)(f2py_setup_aaa);
}

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
    {"occsurf",-1,{{-1}},0,0,(char *)  F_FUNC(occsurf,OCCSURF),  (f2py_init_func)f2py_rout_occsurf75_occsurf,doc_f2py_rout_occsurf75_occsurf},
    {"aa1to3",-1,{{-1}},0,0,(char *)  F_FUNC(aa1to3,AA1TO3),  (f2py_init_func)f2py_rout_occsurf75_aa1to3,doc_f2py_rout_occsurf75_aa1to3},
    {"aadist",-1,{{-1}},0,0,(char *)  F_FUNC(aadist,AADIST),  (f2py_init_func)f2py_rout_occsurf75_aadist,doc_f2py_rout_occsurf75_aadist},
    {"getsfe",-1,{{-1}},0,0,(char *)  F_FUNC(getsfe,GETSFE),  (f2py_init_func)f2py_rout_occsurf75_getsfe,doc_f2py_rout_occsurf75_getsfe},

/*eof routine_defs*/
    {NULL}
};

static PyMethodDef f2py_module_methods[] = {

    {NULL,NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "occsurf75",
    NULL,
    -1,
    f2py_module_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_occsurf75(void) {
    int i;
    PyObject *m,*d, *s, *tmp;
    m = occsurf75_module = PyModule_Create(&moduledef);
    Py_SET_TYPE(&PyFortran_Type, &PyType_Type);
    import_array();
    if (PyErr_Occurred())
        {PyErr_SetString(PyExc_ImportError, "can't initialize module occsurf75 (failed to import numpy)"); return m;}
    d = PyModule_GetDict(m);
    s = PyUnicode_FromString("1.25.1");
    PyDict_SetItemString(d, "__version__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString(
        "This module 'occsurf75' is auto-generated with f2py (version:1.25.1).\nFunctions:\n"
"    occsurf()\n"
"    aa1to3(strng,onelc)\n"
"    aadist()\n"
"    getsfe(onelc,sfdeaa,sfdeaai,bstotal,estotal)\n"
"COMMON blocks:\n""  /aaa/ sfeaa(20,10),aaname(20,3),a1c(20,1),sfe(20)\n"".");
    PyDict_SetItemString(d, "__doc__", s);
    Py_DECREF(s);
    s = PyUnicode_FromString("1.25.1");
    PyDict_SetItemString(d, "__f2py_numpy_version__", s);
    Py_DECREF(s);
    occsurf75_error = PyErr_NewException ("occsurf75.error", NULL, NULL);
    /*
     * Store the error object inside the dict, so that it could get deallocated.
     * (in practice, this is a module, so it likely will not and cannot.)
     */
    PyDict_SetItemString(d, "_occsurf75_error", occsurf75_error);
    Py_DECREF(occsurf75_error);
    for(i=0;f2py_routine_defs[i].name!=NULL;i++) {
        tmp = PyFortranObject_NewAsAttr(&f2py_routine_defs[i]);
        PyDict_SetItemString(d, f2py_routine_defs[i].name, tmp);
        Py_DECREF(tmp);
    }




/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

  tmp = PyFortranObject_New(f2py_aaa_def,f2py_init_aaa);
  if (tmp == NULL) return NULL;
  if (F2PyDict_SetItemString(d, "aaa", tmp) == -1) return NULL;
  Py_DECREF(tmp);
/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
    if (! PyErr_Occurred())
        on_exit(f2py_report_on_exit,(void*)"occsurf75");
#endif
    return m;
}
#ifdef __cplusplus
}
#endif
