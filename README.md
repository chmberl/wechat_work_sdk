# wechat_work_sdk

用PyObject封装了企业微信会话存档的SDK

# install

cd wesdk && python3 setup.py build_ext --inplace

```python
from wesdk import wx_work

sdk = wx_work.NewSdk()

wx_work.Init(self.sdk, "替换CORP_ID", "CORP_SECRET")

```
