#include "Python.h"
#include "WeWorkFinanceSdk_C.h"

/* WeWorkFinanceSdk_t* NewSdk(); */
static PyObject *py_newsdk() {
    WeWorkFinanceSdk_t* result;
    result = NewSdk();
    return Py_BuildValue("l", result);
}

/* int Init(WeWorkFinanceSdk_t* sdk, const char* corpid, const char* secret); */
static PyObject *py_init(PyObject *self, PyObject *args) {
    WeWorkFinanceSdk_t* sdk;
    int result;
    char* corpid;
    char* secret;

    if (!PyArg_ParseTuple(args,"lzz", &sdk, &corpid, &secret)) {
        return NULL;
    }
    result = Init(sdk, corpid, secret);
    return Py_BuildValue("l", result);
}

/* int GetChatData(WeWorkFinanceSdk_t* sdk, unsigned long long seq, unsigned int limit, const char *proxy,const char* passwd, int timeout,Slice_t* chatDatas); */
static PyObject *py_get_chart_data(PyObject *self, PyObject *args) {
    int result;
    WeWorkFinanceSdk_t* sdk;
    unsigned long long seq;
    unsigned int limit;
    char* proxy;
    char* passwd;
    int timeout;
    Slice_t* chatDatas;

    if (!PyArg_ParseTuple(args,"lKIzzil", &sdk, &seq, &limit, &proxy, &passwd, &timeout, &chatDatas)) {
        return NULL;
    }
    result = GetChatData(sdk, seq, limit, proxy, passwd, timeout, chatDatas);
    return Py_BuildValue("l", result);
}

/* Slice_t* NewSlice(); */
static PyObject *py_new_slice(PyObject *self, PyObject *args) {
    Slice_t* result;
    result = NewSlice();
    return Py_BuildValue("l", result);
}

/* void FreeSlice(Slice_t* slice); */
static PyObject *py_free_slice(PyObject *self, PyObject *args) {
    Slice_t* sle;
    if (!PyArg_ParseTuple(args,"l", &sle)) {
        return NULL;
    }
    FreeSlice(sle);
    return Py_BuildValue("s", NULL);
}

/* void DestroySdk(WeWorkFinanceSdk_t* sdk); */
static PyObject *py_destroySdk(PyObject *self, PyObject *args) {
    WeWorkFinanceSdk_t* sdk;
    if (!PyArg_ParseTuple(args,"l", &sdk)) {
        return NULL;
    }
    DestroySdk(sdk);
    return Py_BuildValue("s", NULL);
}

/* char* GetContentFromSlice(Slice_t* slice); */
static PyObject *py_getContentFromSlice(PyObject *self, PyObject *args) {
    Slice_t* sle;
    char* result;

    if (!PyArg_ParseTuple(args,"l", &sle)) {
        return NULL;
    }
    result = GetContentFromSlice(sle);
    return Py_BuildValue("s", result);
}

/* int GetSliceLen(Slice_t* slice); */
static PyObject *py_getSliceLen(PyObject *self, PyObject *args) {
    Slice_t* sle;
    int result;

    if (!PyArg_ParseTuple(args,"l", &sle)) {
        return NULL;
    }
    result = GetSliceLen(sle);
    return Py_BuildValue("l", result);
}

/* int DecryptData(const char* encrypt_key, const char* encrypt_msg, Slice_t* msg); */
static PyObject *py_DecryptData(PyObject *self, PyObject *args) {
    int result;
    char* encrypt_key;
    char* encrypt_msg;
    Slice_t* msg;

    if (!PyArg_ParseTuple(args,"zzl", &encrypt_key, &encrypt_msg, &msg)) {
        return NULL;
    }
    result = DecryptData(encrypt_key, encrypt_msg, msg);
    return Py_BuildValue("l", result);
}


/* MediaData_t*  NewMediaData(); */
static PyObject *py_NewMediaData(PyObject *self, PyObject *args) {
    MediaData_t* result;
    result = NewMediaData();
    return Py_BuildValue("l", result);
}

/* void FreeMediaData(MediaData_t* media_data); */
static PyObject *py_FreeMediaData(PyObject *self, PyObject *args) {
    MediaData_t* md;
    if (!PyArg_ParseTuple(args,"l", &md)) {
        return NULL;
    }
    FreeMediaData(md);
    return Py_BuildValue("s", NULL);
}

/* char* GetOutIndexBuf(MediaData_t* media_data); */
static PyObject *py_GetOutIndexBuf(PyObject *self, PyObject *args) {
    MediaData_t* md;
    char* result;
    if (!PyArg_ParseTuple(args,"l", &md)) {
        return NULL;
    }
    result = GetOutIndexBuf(md);
    return Py_BuildValue("s", result);
}

/*  char* GetData(MediaData_t* media_data); */
static PyObject *py_GetData(PyObject *self, PyObject *args) {
    MediaData_t* md;
    char* result;
    if (!PyArg_ParseTuple(args,"l", &md)) {
        return NULL;
    }
    Py_ssize_t len = GetDataLen(md);
    result = GetData(md);
    return Py_BuildValue("y#", result, len);
}

/*  int GetIndexLen(MediaData_t* media_data); */
static PyObject *py_GetIndexLen(PyObject *self, PyObject *args) {
    MediaData_t* md;
    int result;
    if (!PyArg_ParseTuple(args,"l", &md)) {
        return NULL;
    }
    result = GetIndexLen(md);
    return Py_BuildValue("l", result);
}

/*  int GetDataLen(MediaData_t* media_data); */
static PyObject *py_GetDataLen(PyObject *self, PyObject *args) {
    MediaData_t* md;
    int result;
    if (!PyArg_ParseTuple(args,"l", &md)) {
        return NULL;
    }
    result = GetDataLen(md);
    return Py_BuildValue("l", result);
}

/*  int IsMediaDataFinish(MediaData_t* media_data); */
static PyObject *py_IsMediaDataFinish(PyObject *self, PyObject *args) {
    MediaData_t* md;
    int result;
    if (!PyArg_ParseTuple(args,"l", &md)) {
        return NULL;
    }
    result = IsMediaDataFinish(md);
    return Py_BuildValue("l", result);
}

/* 
int GetMediaData(WeWorkFinanceSdk_t* sdk, const char* indexbuf,
                     const char* sdkFileid,const char *proxy,const char* passwd, int timeout, MediaData_t* media_data);
*/
static PyObject *py_GetMediaData(PyObject *self, PyObject *args) {
    int result;
    WeWorkFinanceSdk_t* sdk;
    const char* indexbuf;
    const char* sdkFileid;
    const char* proxy;
    const char* passwd;
    int timeout;
    MediaData_t* media_data;

    if (!PyArg_ParseTuple(args,"lzzzzil", &sdk, &indexbuf, &sdkFileid, &proxy, &passwd, &timeout, &media_data)) {
        return NULL;
    }
    result = GetMediaData(sdk, indexbuf, sdkFileid, proxy, passwd, timeout, media_data);
    return Py_BuildValue("l", result);
}


/* Module method table */
static PyMethodDef WX_WorkMethods[] = {
  {"NewSdk",  py_newsdk, METH_VARARGS, ""},
  {"NewSlice",  py_new_slice, METH_VARARGS, ""},
  {"FreeSlice",  py_free_slice, METH_VARARGS, ""},
  {"GetContentFromSlice",  py_getContentFromSlice, METH_VARARGS, ""},
  {"GetSliceLen",  py_getSliceLen, METH_VARARGS, ""},
  {"DestroySdk",  py_destroySdk, METH_VARARGS, ""},
  {"Init",  py_init, METH_VARARGS, ""},
  {"GetChatData",  py_get_chart_data, METH_VARARGS, ""},
  {"DecryptData",  py_DecryptData, METH_VARARGS, ""},
  {"GetMediaData",  py_GetMediaData, METH_VARARGS, ""},
  {"NewMediaData",  py_NewMediaData, METH_VARARGS, ""},
  {"FreeMediaData",  py_FreeMediaData, METH_VARARGS, ""},
  {"GetOutIndexBuf",  py_GetOutIndexBuf, METH_VARARGS, ""},
  {"GetData",  py_GetData, METH_VARARGS, ""},
  {"GetIndexLen",  py_GetIndexLen, METH_VARARGS, ""},
  {"GetDataLen",  py_GetDataLen, METH_VARARGS, ""},
  {"IsMediaDataFinish",  py_IsMediaDataFinish, METH_VARARGS, ""},
  {NULL, NULL, 0, NULL} 
};

/* Module structure */
static struct PyModuleDef wx_workmodule = {
  PyModuleDef_HEAD_INIT,

  "wx_work",           /* name of module */
  "wx work sdk",  /* Doc string (may be NULL) */
  -1,                 /* Size of per-interpreter state or -1 */
  WX_WorkMethods       /* Method table */
};


/* Module initialization function */
PyMODINIT_FUNC
PyInit_wx_work(void) {
  return PyModule_Create(&wx_workmodule);
}
