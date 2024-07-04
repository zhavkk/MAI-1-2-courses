let eps = 0.000001

let rec dichotomy f a b = 
    if (b - a) <= eps then  
        ((a + b) / 2.)
    else
        let c = (a + b) / 2.
        if ((f b) * (f c)) < 0. then 
            dichotomy f c b
        else
            dichotomy f a c

let rec iter f acc =
    let cur_res = f acc
    if (abs (cur_res - acc)) <= eps then 
        cur_res
    else 
        iter f cur_res

let iterations phi x0 = iter (fun acc -> (phi acc)) x0

let newton f f' x0 = iter (fun acc -> acc - (f acc) / (f' acc)) x0

let f1 x = 0.6 * 3.0 ** x - 2.3 * x - 3.0
let f2 x = x * x - log(1.0 + x) - 3.0
let f3 x = 2.0 * x * sin(x) - cos(x)

let f1' x = 0.6 * 3.0 ** x - 2.3
let f2' x = 2.0 * x - 1.0 / (1.0 + x)
let f3' x = 2.0 * x * cos(x) + 2.0 * sin(x)

let phi1 x = log(x) + 1.8
let phi2 x = sqrt(log(1.0 + x) + 3.0)
let phi3 x = acos(cos(x) / (2.0 * x))

let main = 
    printfn "%10.5f  %10.5f %10.5f" (dichotomy f1 2. 3.) (iterations phi1 2.) (newton f1 f1' 2.5)
    printfn "%10.5f  %10.5f %10.5f" (dichotomy f2 2. 3.) (iterations phi2 1.) (newton f2 f2' 0.5)
    printfn "%10.5f  %10.5f %10.5f" (dichotomy f3 0.4 1.) (iterations phi3 1.5) (newton f3 f3' 1.5)
