    #include <stdio.h>  
    #include <stdlib.h>  
    #include <string.h>  
    #include <openssl/sha.h>  
    #include <openssl/rsa.h>  
    void testRSAGen(){  
        RSA *r;  
        int bits=512,ret;  
        unsigned long e=RSA_3;  
        BIGNUM  *bne;  
        r=RSA_generate_key(bits,e,NULL,NULL);  
        RSA_print_fp(stdout,r,11);  
        printf("--------------------------------/n");  
        RSA_free(r);  
        bne=BN_new();  
        ret=BN_set_word(bne,e);  
        r=RSA_new();  
        ret=RSA_generate_key_ex(r,bits,bne,NULL);  
        if(ret!=1)  
        {  
        printf("RSA_generate_key_ex err!/n");  
        return -1;  
        }  
        //RSA_print_fp(stdout,r,11);  
        RSA_free(r);  
      
    }  
    void testRSA(){  
        RSA *r;  
        BIGNUM *bne,*bnn,*bnd;  
      
        int bits = 1024, ret, len, flen, padding, i;  
      
        unsigned char *key, *p;  
        BIO *b;  
        //要加密的明文  
        unsigned  char *in = "abcef";  
        unsigned  char *encData,*decData,*tmpData;//加密后的数据/解密后的数据/临时指针  
      
        //使用的密匙数据  
        unsigned long e = 75011;  
        const char *MODULUS="9EC7D9A2DC5B095F8E5F90295121F41262FAEFBE9AF57B772A71F1F9D9635F8769CB78DA2BCFE9B27FC1F3AD4A3D178F8C61981225EF5DEACBDC5665F12E691AA13DDD321A59CFCF376F002036612FF3C5E057A3007FF675AFA3EDE34DC23A1A2637294870EBE823F76B5CE21E25F3FA5137F5DE12437DE0118245B927B28221";  
        const char *PRIVATE="8B26E30ECA6E8F3668F6FA78B0C55FB75A4A3FAD0667B152933A4991D7A815D1498F5E1EF44ACEF6CDF252E56F367DED5BA024DF6B267B7E36BD35552DFA0A4CC1E9D0A4BC8E7C76F98D4971441D6693745A0A76E175571BD160E4B1536A6EFF5A08EDA45236E96E7A4748CF4D031CA8B2F4CCE9F2E1286F432DE6495A535E43";  
      
        //构建RSA数据结构  
        bne = BN_new();  
        bnd = BN_new();  
        bnn = BN_new();  
        ret = BN_set_word(bne, e);  
        BN_hex2bn(&bnd, PRIVATE);  
        BN_hex2bn(&bnn, MODULUS);  
      
        r = RSA_new();  
        r->e=bne;  
        r->d=bnd;  
        r->n=bnn;  
        RSA_print_fp(stdout, r, 5);  
      
        //准备输出的加密数据结构  
        flen =  RSA_size(r);// - 11;  
        encData =  (unsigned char *)malloc(flen);  
        bzero(encData, flen);//memset(encData, 0, flen);  
      
        printf("Begin RSA_private_encrypt .../n");  
        ret =  RSA_private_encrypt(flen, in, encData, r,  RSA_NO_PADDING);  
        if(ret < 0){  
            printf("Encrypt failed!/n");  
            return;  
        }  
        printf("Size:%d/n", ret);  
        printf("ClearText:%s/n", in);  
        printf("CipherText(Hex):/n");  
        tmpData=encData;  
        for  (i=0; i<ret; i++){  
            printf("0x%02x, ", *tmpData);  
            tmpData++;  
        }  
        printf("end private encrypt /n");  
        printf("------------------------/n");  
      
      
        //准备输出的解密数据结构  
        flen =  RSA_size(r);// - 11;  
        decData =  (unsigned char *)malloc(flen);  
        bzero(decData, flen);//memset(encData, 0, flen);  
      
        printf("Begin RSA_public_decrypt .../n");  
        ret =  RSA_public_decrypt(flen, encData, decData, r,  RSA_NO_PADDING);  
        if(ret < 0){  
                printf("RSA_public_decrypt failed!/n");  
                return;  
        }  
        printf("Size:%d/n", ret);  
        printf("ClearText:%s/n", decData);  
      
        free(encData);  
        free(decData);  
        RSA_free(r);  
      
    }  
    void testSHA256(){  
        unsigned char in[]="asdfwerqrewrasfaser";  
        unsigned char out[32];  
      
        size_t n;  
        int i;  
      
        n=strlen((const char*)in);  
      
        SHA256(in,n,out);  
        printf("/n/nSHA256 digest result:/n");  
      
        printf("%d/n",sizeof(out));  
      
        for(i=0;i<32;i++)  
            printf("%d",out[i]);  
        printf("/n");  
      
    }  
    int main(void) {  
        puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */  
        testSHA256();  
        testRSA();  
        return EXIT_SUCCESS;  
    }  