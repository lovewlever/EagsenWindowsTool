# EagsenWindowsTool

```
    
    .\apktool d .\云联_国际版_10000_1.0.0.0_2024_08_30_16_.apk -o yunlianresource
    .\apktool b yunlianresource -o eagsen_unsign.apk --use-aapt2
    E:\SDK\Android\build-tools\34.0.0\zipalign.exe -v 4 .\eagsen_unsign.apk eagsen_unsign_aligned.apk
    E:\SDK\Android\build-tools\34.0.0\apksigner.bat sign -verbose --ks .\668.keystore --out eagsen_signed.apk .\eagsen_unsign_aligned.apk
    
```
