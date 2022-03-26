# setup.py
from distutils.core import setup, Extension

setup(name='wx_work',
      ext_modules=[
        Extension('wx_work',
            ['pywx_work.c'],
            define_macros = [],
            undef_macros = [],
            library_dirs = ['.'],
            libraries = ['WeWorkFinanceSdk_C']
        )
    ]
)
