//
//  NetworkClient.m
//  StarCloud
//
//  Created by Steven.W on 16/6/6.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "NetworkClient.h"
@implementation NetworkClient

#pragma mark -  每个接口必走方法！！！！！
-(void)checkTime{
    UserDefaultsSetObj([DateUtil getNowtime], NEWLOGTIME);
    [DateUtil lessFiveHour];
    
}
#pragma mark 向request中赋值
-(NSDictionary *)setRequestParam:(NSDictionary *)dic {
    //添加共同参数
    NSMutableDictionary *mudic=[NSMutableDictionary dictionaryWithDictionary:dic];
    return mudic;
}
-(void)getSimple_RequestWithData:(NSDictionary *)dict
                      Methodname:(NSString *)mname
                          DESkey:(NSString *)key
                              fi:(FinishBlock)Fiblock
                              fa:(FinishBlock)Fablock{
    NSLog(@"requestURL = %@",mname);
    [self checkTime];
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.requestSerializer=[AFHTTPRequestSerializer serializer];
    manager.requestSerializer.timeoutInterval=20;
    //加密
    if (key) {
        [manager.requestSerializer setValue:key forHTTPHeaderField:HEADER_SECRET]; // 设置请求头
    }
    if ([mname containsString:@" "]) {
        mname = [mname stringByReplacingOccurrencesOfString:@" " withString:@""];
    }
    [manager GET:mname parameters:nil progress:^(NSProgress * _Nonnull downloadProgress) {
        
    }
         success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
             if (responseObject) {
                 Fiblock(responseObject);
             }
         }
         failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull   error) {
             if (error) {
                 Fablock(error.domain);
             }
         }];
}
-(void)postSimple_RequestWithData:(id)dict
                       Methodname:(NSString *)mname
                           DESkey:(NSString *)key
                               fi:(FinishBlock)Fiblock
                               fa:(FinishBlock)Fablock{
    NSLog(@"requestURL = %@",mname);
    if ([UserDefaultsGetObj(TIMETOGETREFSH) isEqualToString:@"isfirst"]) {
        
    }else{
        [self checkTime];
    }
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.responseSerializer = [AFHTTPResponseSerializer serializer];
    manager.requestSerializer=[AFHTTPRequestSerializer serializer];
    manager.requestSerializer.timeoutInterval=20;
    //加密
    if (key) {
        [manager.requestSerializer setValue:key forHTTPHeaderField:HEADER_SECRET]; // 设置请求头
    }
    [manager POST:mname parameters:dict progress:^(NSProgress * _Nonnull downloadProgress) {
        
    }
          success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
              if (responseObject) {
                  UserDefaultsSetObj(@"notfirst", TIMETOGETREFSH)
                  Fiblock(responseObject);
              }
          }
          failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull   error) {
              if (error) {
                  Fablock(error.domain);
              }
          }];
}
-(void)putSimple_RequestWithData:(NSDictionary *)dict
                        Methodname:(NSString *)mname
                            DESkey:(NSString *)key
                                fi:(FinishBlock)Fiblock
                                fa:(FinishBlock)Fablock{
    [self checkTime];
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.responseSerializer = [AFJSONResponseSerializer serializer];
    manager.requestSerializer=[AFHTTPRequestSerializer serializer];
    manager.requestSerializer.timeoutInterval=20;
    //加密
    if (key) {
        [manager.requestSerializer setValue:key forHTTPHeaderField:HEADER_SECRET]; // 设置请求头
    }
    NSLog(@"requestURL = %@",mname);
    [manager PUT:mname parameters:dict success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        if (responseObject) {
            Fiblock(responseObject);
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull   error) {
        if (error) {
            Fablock(error.domain);
        }
    }];
}
-(void)deleteSimple_RequestWithData:(NSDictionary *)dict
                        Methodname:(NSString *)mname
                            DESkey:(NSString *)key
                                fi:(FinishBlock)Fiblock
                                fa:(FinishBlock)Fablock{
    [self checkTime];
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.responseSerializer = [AFJSONResponseSerializer serializer];
    manager.requestSerializer=[AFHTTPRequestSerializer serializer];
    manager.requestSerializer.timeoutInterval=20;
    //加密
    if (key) {
        [manager.requestSerializer setValue:key forHTTPHeaderField:HEADER_SECRET]; // 设置请求头
    }
    NSLog(@"requestURL = %@",mname);
    [manager DELETE:mname parameters:dict success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        if (responseObject) {
            Fiblock(responseObject);
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull   error) {
        if (error) {
            Fablock(error.domain);
        }
    }];
}
// 上传日志
-(void)postJson_RequestWithData:(id)json
                     Methodname:(NSString *)mname
                         DESkey:(NSString *)key
                             fi:(FinishBlock)Fiblock
                             fa:(FinishBlock)Fablock
{
    [self checkTime];
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.responseSerializer = [AFHTTPResponseSerializer serializer];
    manager.requestSerializer = [AFJSONRequestSerializer serializer];
    manager.requestSerializer.timeoutInterval=20;
    
    //加密
    if (key) {
        [manager.requestSerializer setValue:key forHTTPHeaderField:HEADER_SECRET]; // 设置请求头
    }
    [manager POST:mname parameters:json progress:^(NSProgress * _Nonnull downloadProgress) {
        NSLog(@"requestURL = %@",mname);
    }
          success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
              if (responseObject) {
                  Fiblock(responseObject);
              }
          }
          failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull   error) {
              if (error) {
                  Fablock(error.domain);
              }
          }];
}
@end
