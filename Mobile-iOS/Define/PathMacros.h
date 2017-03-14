//
//  PathMacros.h
//  STWangzeping
//
//  Created by mac on 16/5/30.
//  Copyright © 2016年 mac. All rights reserved.
//

#ifndef PathMacros_h
#define PathMacros_h

//文件目录
#define kPathTemp                   NSTemporaryDirectory()
#define kPathDocument               [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define kPathCache                  [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define kPathSearch                 [kPathDocument stringByAppendingPathComponent:@"Search.plist"]


#endif /* PathMacros_h */
