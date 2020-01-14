c++ 컴파일 안되는 문제
![](./img/image-20200114164348049.png)


다음과 같이 수정해줌
```json
"args": [
                "${fileBasenameNoExtension}.cpp",
                "-o",
                "${fileBasenameNoExtension}.exe"
            ]
```

