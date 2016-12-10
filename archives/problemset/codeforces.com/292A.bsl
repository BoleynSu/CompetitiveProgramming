data Int where ffi ` void `

data Unit where {
  Unit:Unit
}

data Bool where {
  False:Bool;
  True:Bool
}

data Maybe a where {
  Just:forall a.a->Maybe a;
  Nothing:forall a.Maybe a
}

data List a where {
  Nil:forall a.List a;
  Cons:forall a.a->List a->List a
}

data IOImpl a where {
  Read:forall a.(Maybe Int->a)->IOImpl a;
  Write:forall a.Int->a->IOImpl a
}

data IO a where {
  Pure:forall a.a->IO a;
  Free:forall a.IOImpl (IO a)->IO a
}

data Pair a b where {
  Pair:forall a.forall b.a->b->Pair a b
}

let fmap = \f -> \x -> case x of {
  Write s k -> Write s (f k);
  Read k -> Read (\s -> f (k s))
} in
let return = Pure in
rec bind = \x -> \f -> case x of {
  Pure x -> f x;
  Free x -> Free (fmap (\y -> bind y f) x)
} in
let getInt = Free (Read (\x -> return x)) in
let putInt = \x -> Free (Write x (return Unit)) in
rec runIO = \x -> case x of {
  Pure x -> x;
  Free x -> case x of {
    Write c x -> let _ = ffi ` (std::printf("%d\n", (std::intptr_t) $v_bsl_c), nullptr) ` in (runIO x);
    Read g -> let x:Maybe Int = ffi ` [=]() -> void* { int x; if (std::scanf("%d", &x) == 1) return (*((std::function<void*(void*)>*)$v_bsl_Just))((void*) (std::intptr_t) x); else return $v_bsl_Nothing; }() `
              in runIO (g x)
  }
} in

let bnot = \x -> case x of {
  True -> False;
  False -> True
} in

let band = \x -> case x of {
  True -> \x -> x;
  False -> \x -> False
} in

let add:Int->Int->Int = \a -> \b -> ffi ` (void*) (((std::intptr_t) $v_bsl_a) + ((std::intptr_t) $v_bsl_b)) ` in
let neg:Int->Int = \a -> ffi ` (void*) -((std::intptr_t) $v_bsl_a) ` in
let sub:Int->Int->Int = \a -> \b -> ffi ` (void*) (((std::intptr_t) $v_bsl_a) - ((std::intptr_t) $v_bsl_b)) ` in
let mul:Int->Int->Int = \a -> \b -> ffi ` (void*) (((std::intptr_t) $v_bsl_a) * ((std::intptr_t) $v_bsl_b)) ` in
let div:Int->Int->Int = \a -> \b -> ffi ` (void*) (((std::intptr_t) $v_bsl_a) / ((std::intptr_t) $v_bsl_b)) ` in
let mod:Int->Int->Int = \a -> \b -> ffi ` (void*) (((std::intptr_t) $v_bsl_a) % ((std::intptr_t) $v_bsl_b)) ` in
let less:Int->Int->Bool = \a -> \b -> ffi ` (((std::intptr_t) $v_bsl_a) < ((std::intptr_t) $v_bsl_b))?$v_bsl_True:$v_bsl_False ` in
let eq0 = \a -> ffi ` ((std::intptr_t) $v_bsl_a) == 0?$v_bsl_True:$v_bsl_False ` in
rec gcd = \a -> \b -> case eq0 a of {
  True -> b;
  False -> gcd (mod b a) a
} in
let max = \x -> \y -> case less x y of {
  True -> y;
  False -> x
} in

rec concat = \a -> \b -> case a of {
  Nil -> b;
  Cons x xs -> Cons x (concat xs b)
} in
rec filter = \list -> \f -> case list of {
  Nil -> Nil;
  Cons x xs -> case f x of {
    True -> Cons x (filter xs f);
    False -> filter xs f
  }
} in
let sort = \less ->
  rec sortLess = \list -> case list of {
    Nil -> Nil;
    Cons x xs -> concat (sortLess (filter xs (\y -> bnot (less x y))))
                 (Cons x (sortLess (filter xs (less x) )))
  } in sortLess
in

rec getList = bind getInt \x -> case x of {
  Just x -> bind getList \xs ->
            return (Cons x xs);
  Nothing -> return Nil
} in
rec putList = \list -> case list of {
  Nil -> return Unit;
  Cons x xs -> bind (putInt x) \_ ->
               putList xs
} in

rec toList = \x -> case x of {
  Nil->Nil;
  Cons h t -> case t of {
    Cons h_ t_ -> Cons (Pair h h_) (toList t_)
  }
} in

let zero = ffi ` (void*)0 `in
let getAns = \lst ->
  rec
    getAns_ = \l -> \unfinishedTask -> \currentTime -> \maxTask ->
      case l of {
        Nil -> Pair (add currentTime unfinishedTask) maxTask;
        Cons h xs -> case h of {
          Pair t c -> case eq0 (sub t currentTime) of {
            True -> getAns_ xs (add unfinishedTask c) currentTime (max maxTask (add unfinishedTask c));
            False -> getAns_ (Cons (Pair t c) xs) (max (add (sub unfinishedTask t) currentTime) zero) t maxTask
          }
        }
      }
  in getAns_ lst zero zero zero
in
let fst = \x -> case x of {
  Pair f _ -> f
} in
let snd = \x -> case x of {
  Pair _ s -> s
} in
let tail = \x -> case x of {
  Cons _ t -> t
} in

let main =
  bind getList \numbers->
  let ans = getAns (toList (tail numbers)) in
  bind (putInt (fst ans)) \_->
  putInt (snd ans)
in runIO main
