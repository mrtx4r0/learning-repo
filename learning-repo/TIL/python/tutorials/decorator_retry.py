#!/usr/bin/env python3

import random
# from retrying import retry
from tenacity import retry, stop_after_attempt

@retry(
    stop=stop_after_attempt(3), # stopキーワード引数にstop_after_attemptでリトライ回数を設定する
)
def my_func():
    if random.randint(0,10) == 5:
        print('5です')
    else:
        print('raise ValueError')
        raise ValueError('5ではありません')

my_func()
