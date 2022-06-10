import struct


def main(data):
    A = struct.unpack_from('<2HI', data, offset=4)

    B = struct.unpack_from('<qdq4b2fq4b2fq4b2fqH7ihH', data, offset=A[1])

    D = struct.unpack_from('<8hqBdh', data, offset=A[2])

    return {'A1': A[0],
            'A2': {'B1': B[0],
                   'B2': B[1],
                   'B3': B[2],
                   'B4': [{'C1': [B[3], B[4], B[5], B[6]],
                           'C2': B[7],
                           'C3': B[8],
                           'C4': B[9]},
                          {'C1': [B[10], B[11], B[12], B[13]],
                           'C2': B[14],
                           'C3': B[15],
                           'C4': B[16]},
                          {'C1': [B[17], B[18], B[19], B[20]],
                           'C2': B[21],
                           'C3': B[22],
                           'C4': B[23]}],
                   'B5': B[24],
                   'B6': [B[25], B[26], B[27], B[28], B[29], B[30], B[31]],
                   'B7': B[32],
                   'B8': B[33]},
            'A3': {'D1': [D[0], D[1], D[2], D[3], D[4], D[5], D[6], D[7]],
                   'D2': D[8],
                   'D3': D[9],
                   'D4': D[10],
                   'D5': D[11]}}

# print(main(b'LIG\xc3\xf9g\x0c\x00\x82\x00\x00\x00\xcb\xba\xb3yV\x87CC\x9e\xa5\x16.'
#            b'Y\xb9\xe7\xbf>\xc5 \xbb\xa8c\xd6\x9e\x8f\xf8\xba\x1c\xf6\x03\xd3>PNH>'
#            b'\xd1\xdf\x05\x91\x8fa\x0cu\xf8x,\xdf\x86yv\xbfd\x8f^?\xc2z\xb7\x8c'
#            b'\xa7\x92}\x80\xb3\x1fu\x8e\xfd\xa0\x08>\xf8{\x18?\xaf+T\x08\xdbVp\x83'
#            b'\xa7\xf8\xc0u\xd0\xf3\xca\xa3\t\x83\xf9\xbe\x8f$\xae_\x1a\\OM\xcc_\x9c\x13'
#            b'\xf6\x7f\xe7\xb4\x06g\x989\xf4\x02>\xac\xed\xb7\x18e\xd8\xbb~E*\xdb&\xf1'
#            b'L\xe3\xe1`:\xd7Bg\x93\xeb\xce\xc8\xe9\xfbrN6\xc2?!\xf6'))

# A - <2HI
# B - <qdq4b2fq4b2fq4b2fqH7ihH
# C - <4b2fq
# D - <8hqBdh
