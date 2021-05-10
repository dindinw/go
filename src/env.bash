if [[ "$GOROOT" == *:* ]]; then
  GOROOT=$(cd "$GOROOT"; pwd)
fi

if [[ "$GOBIN" == *:* ]]; then
  GOBIN=$(cd "$GOBIN"; pwd)
fi

export GOROOT=${GOROOT:-$(cd ..; pwd)}
export GOOS=darwin
export GOARCH=amd64


